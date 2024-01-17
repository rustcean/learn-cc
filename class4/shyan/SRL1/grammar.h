#ifndef _GRAMMAR_H_
#define _GRAMMAR_H_

#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Project { //��Ŀ
public:
    string key; //��Ŀ��key
    int value_num; //��Ŀkey��Ӧ��value�ı��
    int index; //����λ��
    int type; //1Ϊ�ƽ��� 2Ϊ��Լ��
    Project(string a = "", int b = 0, int c = 0, int d = 1) {
        this->key = a;
        this->value_num = b;
        this->index = c;
        this->type = d;
    }
    bool operator == (const Project& other) {
        return (this->key == other.key) && (this->value_num == other.value_num) && (this->index == other.index) && (this->type == other.type);
    }
};

class Grammar {
private:
    map<string, vector<vector<string>>> m; //��¼�ķ���ÿһ������ʽ��ͨ����ֵ�Եķ�ʽ
    string start;  //��¼��ʼ����
    set<string> ntSet; //�ս������
    map<string, set<string>> m_first; //��¼ÿһ�����ս���Ŷ�Ӧ��first����
    map<string, set<string>> m_follow; //��¼ÿһ�����ս����Ӧ��follow����
    vector<vector<Project>> DFA_nodes; //��¼DFA���
    map<int, map<string, int>> forwards; //��¼�ƽ���ϵ
    map<int, map<string, int>> backs; //��¼��Լ��ϵ
    bool isSLR1; //�Ƿ�ΪSLR(1)�ķ�
    string reason; //����SLR(1)�ķ���ԭ��
public:
    Grammar(string inputString = ""); //���캯��(��ɳ�ʼ������)
    string get_start(); //�õ���ʼ����
    set<string> get_ntSet();  //�õ��ս����
    set<string> get_first(string key); //�õ����ս��key��first����
    set<string> get_follow(string key);//�õ����ս��key��follow����
    string show(); //չʾ�ķ�
    string parse(string sentence); //����
private:
    void first_follow_all(); //�����з��ս����first��follow����
    set<string> first(vector<string> value); //��value���е�first����
    void node_relationship(); //��DFAͼ��˳��ѹ�Լ��ϵҲ���ˣ�˳���ж��Ƿ�ΪSLR1
    void extend(int k); //��չ���k
};

#endif
