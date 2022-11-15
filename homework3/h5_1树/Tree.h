#ifndef TREE_H
#define TREE_H
#define MaxSons 6
#include <string.h>
//数组数据节点
struct TreeR
{
    std::string maindata;  
    std::string childata;
};

//树节点
struct TreeNode
{
    std::string data;         //节点值
    TreeNode *sons[MaxSons]; //指向孩子节点
};

//树
class Tree{
    public:
    //函数
    TreeNode * createTree(std::string data,TreeR *R,int num);
    void PrinTree(TreeNode *head);
    void ClearTree(TreeNode *t);
    TreeNode *Find(TreeNode *t,std::string str);
    int Countchild(TreeNode *t);
    int leafcount(TreeNode *t);
    int Sum(TreeNode *t);
};


#endif