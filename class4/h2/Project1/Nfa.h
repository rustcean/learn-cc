#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <fstream>
#include <stdio.h>

using namespace std;


struct dfa
{
	int id;			//本状态的序号
	set<int> now;   //本状态
	map<char, set<int>> next;   //下一个状态
};



class Nfa
{
	//nfa
	string re;		//正则表达式
	string re_;		//带连接符的正则表达式
	string pe;		//正则的后缀形式
	int stateNum_NFA;	//状态数
	int stateNum_DFA; //DFA状态数
	int stateNum_mini;//mini状态数
	pair<int, int> se;	//起点和终点状态编号
	vector<vector<pair<int, char>>> graphNFA;	//NFA状态关系图
	set<char> charstring;	//记录所有char符号-费运算符
	struct dfa graphDFA[100];//DFA初步
	map<set<int>, int>mp;    //记录dfa的set的编号
	set<int> groups[105]; //mini存状态
	map<int, int>belong; //存各种数字对应

public:
	Nfa(string re);
	void insertContact();
	int priority(char c);	
	void re2Pe();
	int newState();	
	void pe2NFA();
	void printNFA(ofstream& fout);
	//转dfa
	set<int> getSET_DFA(set<int> str);
	void NFA2DFA();
	void printDNF();
	//最小化
	void miniDFA();
	bool check_final(set<int>edge);
	void printDNFmini();
	

	//实现代码输出
	void printCode();


};













