#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
const int maxCitiesNum = 50;

namespace cyy
{
    double maxTime = 0;
    int maxLength = 0;
    double maxBudget = 0.0;
    bool* visited = 0;
    vector<string> route;

    class Graph
    {
    private:
        int verticeNum;
        int maxSize;
        string* cities;
        double** trainPrice;
        double** trainTime;
        double** flightPrice;
        double** flightTime;
    public:
    	vector<string>ans;
        Graph(int x = maxCitiesNum) : verticeNum(0), maxSize(x), cities(new string[x])
        {
            flightPrice = new double* [x];
            flightTime = new double* [x];
            trainPrice = new double* [x];
            trainTime = new double* [x];
            for (int i = 0; i < x; i++)
            {
                flightPrice[i] = new double[x];
                flightTime[i] = new double[x];
                trainPrice[i] = new double[x];
                trainTime[i] = new double[x];
                for (int j = 0; j < x; j++)         // 数据默认全部初始化为-1
                {
                    if (i == j)
                    {
                        flightPrice[i][j] = 0;
                        flightTime[i][j] = 0;
                        trainPrice[i][j] = 0;
                        trainTime[i][j] = 0;
                    }
                    else
                    {
                        flightPrice[i][j] = -1;
                        flightTime[i][j] = -1;
                        trainPrice[i][j] = -1;
                        trainTime[i][j] = -1;
                    }
                }
            }
        }

        ~Graph()
        {
            for (int i = 0; i < maxSize; i++)
            {
                delete[] trainPrice[i];
                delete[] trainTime[i];
                delete[] flightPrice[i];
                delete[] flightTime[i];
            }
        }

        int addCity(string city)        // 添加城市，返回cities下标值（失败为-1）
        {
            if (verticeNum < maxSize)
            {
                cities[verticeNum++] = city;
                return verticeNum - 1;
            }
            else
            {
                cerr << "存储空间已满，添加城市“" << city << "”失败！" << endl;
                return -1;
            }
        }

        int getCityNum(string city, bool add = false)      // 返回city在cities的下标值
        {
            for (int i = 0; i < verticeNum; i++)
            {
                if (cities[i] == city) { return i; }
            }
            if (add) { return addCity(city); }              //（add为真时，添加未搜索到的城市）
            return -1;
        }

        void readFlightData(string filePath)        // 读入飞机票、时间数据
        {
            int col = 0;
            string line; ifstream sin;

            sin.open(filePath);
            if (!sin) {
                cerr << "发生错误：无法打开文件 " << filePath << " !" << endl;
                return;
            }

            int depNum, desNum;
            bool found;
            getline(sin, line);
            while (sin >> line && line != "end")     // 依次输入出发，到达，价格，时间（下方同理）
            {
                switch (col)
                {
                case 0: depNum = getCityNum(line, true); break;
                case 1: desNum = getCityNum(line, true); found = (depNum != -1 && desNum != -1); break;
                case 2: if (found) { flightPrice[depNum][desNum] = _S2D(line); } break;
                case 3: if (found) { flightTime[depNum][desNum] = _S2D(line); } break;
                }
                col++; col %= 4;
            }
            sin.close();
        }

        void readTrainData(string filePath)        // 读入火车票、时间数据
        {
            int col = 0;
            string line; ifstream sin;

            sin.open(filePath);
            if (!sin) {
                cerr << "发生错误：无法打开文件 " << filePath << " !" << endl; // 报错
                return;
            }

            int depNum, desNum;
            bool found;
            getline(sin, line);
            while (sin >> line && line != "end")
            {
                switch (col)
                {
                case 0: { depNum = getCityNum(line, true); break; }
                case 1: { desNum = getCityNum(line, true); found = (depNum != -1 && desNum != -1); break; };
                case 2: { if (found) { trainPrice[depNum][desNum] = _S2D(line); }break; }
                case 3: { if (found) { trainTime[depNum][desNum] = _S2D(line); } break; }
                }
                col++; col %= 4;
            }
            sin.close();
        }

        double getPrice(int a, int b, int type)
        {
            if (type == 1)
            {
                if (trainPrice[a][b] != -1) { return trainPrice[a][b]; }
                else { return trainPrice[b][a]; }
            }
            else
            {
                if (flightPrice[a][b] != -1) { return flightPrice[a][b]; }
                else { return flightPrice[b][a]; }
            }
        }

        double getTime(int a, int b, int type)
        {
            if (type == 1)
            {
                if (trainTime[a][b] != -1) { return trainTime[a][b]; }
                else { return trainTime[b][a]; }
            }
            else
            {
                if (flightTime[a][b] != -1) { return flightTime[a][b]; }
                else { return flightTime[b][a]; }
            }
        }

        void Recommend(string infil, int l, double t, double b, int type)
        {
        	ans.clear();
            int infilNum = getCityNum(infil);
            if (infilNum == -1) { cout << "无该城市数据！" << endl; return; }

            visited = new bool[verticeNum];
            for (int i = 0; i < verticeNum; i++) { visited[i] = false; }
            maxLength = l; maxTime = t; maxBudget = b;
            route.push_back(infil); visited[infilNum] = true;
            BFS(0, t, b, type);
            delete[] visited; route.clear();
        }

        void BFS(int length, double time, double budget, int type)  // 火车type = 1，飞机type != 1
        {
            if (length > maxLength) { return; }

            int infilNum = getCityNum(route[0]);
            int last = getCityNum(route[length]);
            double finalTime = maxTime - time + getTime(last, infilNum, type);          // 计算交通时间、路费
            double finalBudget = maxBudget - budget + getPrice(last, infilNum, type);

            if (infilNum != last && finalBudget <= maxBudget && finalTime <= maxTime)   // 满足条件
            {
            	string s;
                for (int i = 0; i <= length; i++)
                {
                	s+=route[i]+"->";
                    //cout << route[i] << ;
                }
                s+=route[0]+"，预计交通时间（分钟）："+czy::int_to_string(finalTime);
                s+="，预计路费(元)："+czy::int_to_string(finalBudget)+"\n";
                ans.push_back(s);
            }
            for (int i = 0; i < verticeNum; i++)
            {
                if (i == last || visited[i] == true || getTime(last, i, type) == -1) { continue; }      // 跳过目前地点、已去到过的地点、无法到达的地点
                route.push_back(cities[i]); visited[i] = true;
                BFS(length + 1, time - getTime(last, i, type), budget - getPrice(last, i, type), type);
                route.pop_back(); visited[i] = false;
            }
        }

        double _S2D(string s)                    // string -> double（忽略所有非数字符号）
        {
            if (s[0] == '-') { return -1 * _S2D(s.substr(1)); }

            int i = 0, point = -1, acc = 0;
            double result = 0;
            bool invalid = false;

            while (i != s.length())
            {
                if (s[i] == '.' && point == -1) { point = i; i++; continue; }
                else if (s[i] < '0' || s[i] > '9')
                {
                    if (!invalid) {
                        cout << "警告：文件数据出现不合规内容“" << s << "”！" << endl;
                        invalid = true;
                    }
                    i++; continue;
                }
                result *= 10;
                result = result + s[i] - double('0');
                if (point != -1) { acc++; }
                i++;
            }
            while (acc--) { result /= 10; }
            return result;
        }
    };
}
