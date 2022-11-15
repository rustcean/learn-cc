#include <iostream>
#include "Tree.h"
using namespace std;

//建立函数-输入数组第一个数据，数组，数组大小，头结点
TreeNode * Tree::createTree(string data,TreeR *R,int num)
{
    TreeNode *t;
    int i=0,j=0,k;
    t=new TreeNode;
    t->data=data;
    for(k=0;k<MaxSons;k++)
        t->sons[k]=NULL;
    while(i<num)
    {
        if(R[i].maindata==data)
        {
            t->sons[j]=createTree(R[i].childata,R,num);
            j++;
        }
        i++;
    }
    return t;
}

//输出函数-输入头节点
void Tree::PrinTree(TreeNode *head)
{
    int i=0;
    if(head==NULL)
        cout<<"树为空"<<endl;
    else
    {
        cout<<head->data;
        if(head->sons[i]!=NULL)
        {
            cout<<"(";
            for(i=0;i<MaxSons;i++)
            {
                PrinTree(head->sons[i]);
                if(head->sons[i+1]!=NULL)
                    cout<<",";
                else
                    break;
            }
            cout<<")";
        }
    }
}

//清除树
void Tree::ClearTree(TreeNode *t)
{
    if(t==NULL)
        cout<<"空树"<<endl;
    else
    {
        for(int i=0;i<MaxSons;i++)
        {
            if(t->sons[i]!=NULL)
                ClearTree(t->sons[i]);
            else break;
        }
        delete t;
    }
}

//寻找
TreeNode * Tree::Find(TreeNode *t,string str)
{
    TreeNode *p;
    if(t==NULL)
    {cout<<"空树"<<endl;return NULL;}
    else
    {
        if(t->data==str)
            return t;
        else
        {       
        for(int i=0;i<MaxSons;i++)
        {

            if(t->sons[i]!=NULL)
            {
                p=Find(t->sons[i],str);
                if(p!=NULL)
                    return p;
            }
        }
        }
        return NULL;
    }
}

//求孩子个数
int Tree::Countchild(TreeNode *t)
{
    int count=0;
    for(int i=0;i<MaxSons;i++)
    {
        if(t->sons[i]!=NULL)
            count++;
        else break;
    }
    return count;
}

//求最低一级子部门数
int Tree::leafcount(TreeNode *t)
{
    int count=0;
    if(t==NULL)
        return 0;
    else
    {
        if(t->sons[0]==NULL)
            count++;
        else
        {
            for(int i=0;i<MaxSons;i++)
            {
                if(t->sons[i]!=NULL)
                    count=count+leafcount(t->sons[i]);
                else break;
            }
        }
    }
    return count;
}



//求和
int Tree::Sum(TreeNode *t)
{
    int sum=0;
    if(t==NULL)
        return 0;
    else
    {
        if(t->sons[0]==NULL)
            return stoi(t->data);
        else
        {
            for(int i=0;i<MaxSons;i++)
            {
                if(t->sons[i]!=NULL)
                    sum+=Sum(t->sons[i]);
                else break;
            }
        }
    }
    return sum;
}