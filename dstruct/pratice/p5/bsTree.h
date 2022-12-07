#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <cstring>
using namespace std;
//节点类
class Node
{
    public:
    int key;           //关键字
    std::string data;  //数据
    Node *left, *right;//左右指针
    Node():left(NULL),right(NULL){}
    Node(int k,std::string x):key(k),data(x),left(NULL),right(NULL){}
    ~Node(){};
};
//树
class bsTree
{
    private:
    int maxValue(Node* root);//判断最大值函数--辅助判断搜索树
    int minValue(Node* root);//判断最小值函数--辅助判断搜索树
    
    public:
    Node *root;
    bsTree(){root=NULL;}
    ~bsTree(){};
    //功能函数
    Node *Search(Node d, Node * &pr);//查找函数
    bool Insert(Node d);//插入函数
    void createbsTree(Node v[],int n);//创建树
    bool remove(Node d);//删除节点函数
    bool IsbsTree(Node *root);//判断是否为搜索树
};
//查找函数-输入节点，输出节点指针和暗藏的父节点pr
Node *bsTree::Search(Node d, Node* &pr)
{
    Node *p=root;pr=NULL;
    while(p!=NULL)
    {
        if(p->key == d.key) return p;
        else
        {
            pr=p;
            if(d.key < p->key)p=p->left;
            else p=p->right;
        }
    }
    return p;
}
//插入-输入节点，输出布尔
bool bsTree::Insert(Node d)
{
    Node *s,*p,*pr;
    p=Search(d,pr);
    if(p!=NULL)
        return false;

    s=new Node(d.key,d.data);
    if(root==NULL)root=s; //如果是空树，根节点就是s
    else if(d.key < pr->key) pr->left=s;//key小于pr.key,
    else pr->right=s;
    return true;
}
//建立树-建立在前两个函数上
void bsTree::createbsTree(Node v[],int n )
{
    root=NULL;
    for(int i=0;i<n;i++)
    {
        Insert(v[i]);
    }
}
//删除-输入节点-输出布尔
bool bsTree::remove(Node d)
{
    Node *s,*p,*pr;
    p=Search(d,pr);
    if(p==NULL)
    {
        cout<<"节点本不在树中"<<endl;
        return false;
    }
    if(p->left!=NULL && p->right!=NULL)//如果为中间节点
    {
        s=p->right;pr=p;
        while(s->left!=NULL){pr=s,s=s->left;}
        p->key=s->key;
        p->data=s->data;
        p=s;              
    }
    if(p->right==NULL)s=p->left;
    else p=p->right;
    if(p==root)root=s;
    else if(pr->left==p)pr->left=s;
    else pr->right=s;
    delete p;
    return true;
}

//下面进行判断是否为搜索树
int bsTree::maxValue(Node *root)
{
    if(root == NULL)
        return INT8_MAX;
    while(root -> right)
        root = root -> right;
    return root -> key;
}
int bsTree::minValue(Node *root)
{
    if(root == NULL)
        return INT8_MIN;
    while(root -> left)
        root = root -> left;
    return root -> key;
}
bool bsTree::IsbsTree(Node *root)
{
    if (root == NULL)
            return true;
    //如果左子树最大值大于根节点，则返回false
    if (root->left != NULL && maxValue(root->left) > root->key)
            return false;
    //如果右子树最小值小于根节点，则返回false
    if (root->right != NULL && minValue(root->right) < root->key)
            return false;
    //递归判断
    if (!IsbsTree(root->left) || !IsbsTree(root->right))
            return false;
    return true;
}

#endif