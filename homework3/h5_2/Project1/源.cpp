#define  _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include<map>
using namespace std;
#define MAX_SIZE 20
const int N = 1000;

vector<string>R(N);
map<string, int>s1,s3;
map<int, string>vers1;
map<int, vector<int>>s2;
int id_node = 0;
void inittree() {
    ifstream inFile("data1.txt", ios::in);
    string lineStr;

    while (getline(inFile, lineStr),!lineStr.empty())
    {
        stringstream ss(lineStr);
        string str;
        int cnt = 0;
        string pre;
        while (getline(ss, str,'\t'))
        {      
            cnt++;
            int i = 0, nlen = str.size();
            bool flag = 1;
            for (; i < nlen; i++)
            {
                if (str[i] >= 0 && str[i] <= 127) {
                }
                else {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                s3[str] = stoi(str);
                
            }
            if (!s1.count(str)) {
                s1[str] = ++id_node;
                vers1[id_node] = str;
                R[id_node]=str;
            }
            if (cnt % 2 == 0) {
                s2[s1[pre]].push_back(s1[str]);
            }
            pre = str; 
        }

    }
}
void print(string s) {

    cout << s;
    if (s2[s1[s]].empty())return;
    else cout << '(';
    for (int i = 0; i < s2[s1[s]].size(); i++) {
        if(i!=0)cout << ',';
        print(vers1[s2[s1[s]][i]]);
    }
    cout << ')';
}
int findx(string x) {
    return s1[x];
}
int get_subnum(string x) {
    return s2[s1[x]].size();
}
int get_trenum(int x) {

    int res = 0;
    if (s2[x].empty())return 1;
    for (int a : s2[x]) {
        res+=get_trenum(a);
    }
    return res;
}

int get_tresum(int x) {

    int res = 0;
    if (s2[x].empty())return s3[vers1[x]];
    for (int a : s2[x]) {
        res += get_tresum(a);
    }
    return res;
}
int get_subx(string x) {
    return get_subnum(x);
}
int get_trenumx(string x) {
    //cout << x << endl;
    return get_trenum(s1[x]);
}
int get_tresumx(string x) {
    return get_tresum(s1[x]);
}
int main()
{

    inittree();
    
    cout << "Print（）" << endl;
    print(vers1[1]);
    cout << endl;
    cout << " Findx（string x）返回值为x的结点的指针" << endl;
    cout << findx(vers1[1])<<endl;
    cout << "Getsubnum（node* p）p所指结点的孩子个数" << endl;
    cout << get_subnum(vers1[1]) << endl;
    cout << " Getsubx（string x）求树t中x部门的下一级子部门数" << endl;
    cout << get_subx(vers1[1]) << endl;
    cout << " Gettrenum（node* t）求树t中叶子结点个数" << endl;
    cout << get_trenum(1) << endl;
    cout << "Gettrenumx（string x）求树t中x部门的最低一级子部门数" << endl;
    cout << get_trenumx(vers1[1]) << endl;
    cout << " Gettresum（node* p）求树t中叶子结点的数值和" << endl;
    cout << get_tresum(1) << endl;
    cout << "Gettresumx（string x）" << endl;    
    cout << get_tresumx(vers1[1]) << endl;
    cout << endl;


}