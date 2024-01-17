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
	int id;			//��״̬�����
	set<int> now;   //��״̬
	map<char, set<int>> next;   //��һ��״̬
};



class Nfa
{
	//nfa
	string re;		//������ʽ
	string re_;		//�����ӷ���������ʽ
	string pe;		//����ĺ�׺��ʽ
	int stateNum_NFA;	//״̬��
	int stateNum_DFA; //DFA״̬��
	int stateNum_mini;//mini״̬��
	pair<int, int> se;	//�����յ�״̬���
	vector<vector<pair<int, char>>> graphNFA;	//NFA״̬��ϵͼ
	set<char> charstring;	//��¼����char����-�������
	struct dfa graphDFA[100];//DFA����
	map<set<int>, int>mp;    //��¼dfa��set�ı��
	set<int> groups[105]; //mini��״̬
	map<int, int>belong; //��������ֶ�Ӧ

public:
	Nfa(string re);
	void insertContact();
	int priority(char c);	
	void re2Pe();
	int newState();	
	void pe2NFA();
	void printNFA(ofstream& fout);
	//תdfa
	set<int> getSET_DFA(set<int> str);
	void NFA2DFA();
	void printDNF();
	//��С��
	void miniDFA();
	bool check_final(set<int>edge);
	void printDNFmini();
	

	//ʵ�ִ������
	void printCode();


};













