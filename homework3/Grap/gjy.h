#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
namespace gjy{
struct node
{
	string s1, s2;
	int time;
	double price;
	int type;
}a[10005];
int cnt = 0;
int map[105][105] ={0} ;//邻接矩阵
int numberOfVertices=5;		//需提供的数据，即顶点数
const int maxWeight=9999;	//大于该数字即为无直接相连的边，可按情况更改

int GetWeight(int start, int end) {
	//此函数为唯一使用邻接矩阵名的地方，直接更改矩阵名即可
	//此处选择使用时间或距离的邻接矩阵，可分别求得时间最短或路程最短的路径
	return map[start][end];
}

void AllShortestPath(int start, int dist[], int path[]) {//直接复制即可
	int n = numberOfVertices;
	bool* S = new bool[n];
	int w, min;
	for (int i = 0; i < n; i++) {
		dist[i] = GetWeight(start, i);
		S[i] = false;
		if (i != start && dist[i] < maxWeight)path[i] = start;
		else path[i] = -1;
	}
	S[start] = true;
	dist[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		min = maxWeight;
		int u = start;
		for (int j = 0; j < n; j++) {
			if (S[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (int k = 0; k < n; k++) {
			w = GetWeight(u, k);
			if (S[k] == false && w < maxWeight && dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}

int* ShortestPath(int start,int end) {
	//直接调用即可
	//输入两个数字，即出发点和终点，输出的个数为int类型的数组
	//第一个数字为路径的总长度，第二个数字为路径的经过点的总数n（包括起始点和终点）
	//第三个开始的n个点为路径点
	int n = numberOfVertices;
	int path[105];
	int dist[105];
	memset(path,-1,sizeof path);
	memset(dist,-1,sizeof dist);
	AllShortestPath(start, dist,path);
	int* message=new int[n + 3];
	int* temp = new int[n + 3];
	for (int i = 0; i < n + 3; i++)message[i] = -1;
	int step = end;
	int num = 1;
	while (step != start) {
		step = path[step];
		num++;
	}
	message[0] = dist[end];
	message[1] = num;
	message[num+1] = end;
	for (int i = num; i > 1; i--) {
		end = path[end];
		message[i] = end;
	}
	return message;
}
double string_to_double(string s)
{
	double x = 0;
	int j = s.size();
	for (int i = 0; i < s.size(); i++)
	{
		int tp = s[i] - '0';
		if (tp > 10 || tp < 0)
		{
			j = i + 1;
			break;
		}
		x *= 10;
		x += tp;
	}
	double y = 0;
	for (int i = j; i < s.size(); i++)
	{
		int tp = s[i] - '0';
		y *= 10;
		y += tp;
	}
	while (y > 1)y *= 0.1;
	return x + y;
}
void read(int type)
{
	string last;
	string s1, s2, s3, s4;
	getline(cin, s1);//cin.get();
	int time, price;
	while (1)
	{
		cin >> s1;
		if (s1 == "end")break;
		cin >> s2 >> s3 >> s4;
		int time = string_to_double(s4);
		double price = string_to_double(s3);
		a[++cnt] = { s1,s2,time,price,type };
		last = s3;


	}
}
void read_data()
{
	freopen("1.txt", "r", stdin);
	read(1);
	freopen("CON", "r", stdin);
	cin.clear();
	freopen("2.txt", "r", stdin);
	read(2);
	freopen("CON", "r", stdin);
	cin.clear();
}
unordered_map<string, int> init2(int type)
{
	read_data();
	unordered_map<string, int>mp;
	int tot = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (!mp.count(a[i].s1))mp[a[i].s1] = tot++;
		if (!mp.count(a[i].s2))mp[a[i].s2] = tot++;
	}
	gjy::numberOfVertices = tot;
	memset(gjy::map, 63, sizeof gjy::map);
	for (int i = 1; i <= cnt; i++)
	{
		if (a[i].type != type)continue;
		int u = mp[a[i].s1];
		int v = mp[a[i].s2];
		if (type == 1)gjy::map[u][v] = a[i].price;
		else gjy::map[u][v] = a[i].time;
	}
	return mp;
}

}
/*
int main() {
	while (1) {
		cout << "enter start and end:";
		int start, end;
		cin >> start >> end;
		int* mes = ShortestPath(start,end);
		int i = 0;
		while (mes[i] != -1) {
			cout << mes[i] << endl;;
			i++;
		}
	}
	return 0;
}*/
