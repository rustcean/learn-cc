#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;
int main()
{
    
    string filename="company.txt";       //文件名
    TreeR R[50];                 //存储数组
    
    //读取
    ifstream infile(filename);
    if(!infile){cerr<<"company.txt"<<endl;abort();}
    string ch;            //暂存
    int num=0;
    while (getline(infile,ch))//ch中不会读取换行符
    {
        //分割
        string str1="";
        string str2="";
        int i=0;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){str1+=ch[i];}
            else break;
        }
        for(;i<ch.length();i++){
            if(ch[i]!=' '){str2+=ch[i];}
        }
        //存储
        R[num].maindata=str1;
        R[num].childata=str2;
        num++;
    }

    //建树
    Tree P;
    TreeNode *head = P.createTree(R[0].maindata,R,num);
    //广义表输出
    P.PrinTree(head);
    //求某节点孩子数
    cout<<endl;
    cout<<P.Countchild(head)<<endl;;
    //算出叶子数
    cout<<P.leafcount(head)<<endl;
    //找出 
    string str="文学部";
    cout<<P.Find(head,str)->data<<endl;
    //求节点的数目和
    cout<<P.Sum(head)<<endl;



    return 0;
}