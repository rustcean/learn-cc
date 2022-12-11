#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>
using namespace std;

//时间
struct Date
{
    int year;
    int month;
};

//节点类
class Node
{
    public:
    std::string stu_number;  //学号
    std::string stu_name;    //姓名
    std::string stu_sex;     //性别
    std::string phonenumber; //电话号码
    std::string stu_address; //地址
    Date d_date;               //出生日期
    Node *left, *right;//左右指针
    Node():left(NULL),right(NULL){stu_number="";stu_name="";stu_sex="";phonenumber="";stu_address="";}
    Node(std::string n,std::string name,std::string sex,std::string p,std::string a,int y,int m)
    {stu_number=n,left=NULL,right=NULL;stu_address=a;stu_name=name;
    stu_sex=sex;phonenumber=p;stu_address=a;d_date.year=y;d_date.month=m;}
    ~Node(){};
};
//树
class bsTree
{
    public:
    Node *root;
    bsTree(){root=NULL;}
    ~bsTree(){};
    //功能函数
    Node *Search(Node d, Node * &pr); //查找函数
    bool Insert(Node d);              //插入函数
    void createbsTree(Node v[],int n);//创建树
    bool remove(Node d);              //删除节点函数
    void print(Node *p);              //输出函数
    std::string getall(Node *p);      //返回含有数据的字符串
    

};
//输出函数-输入节点-打印出该节点下的所有数据
void bsTree::print(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->stu_name<<"\t"<<p->stu_number<<"\t"<<p->stu_sex<<"\t"<<
        p->phonenumber<<"\t"<<p->stu_address<<"\t"<<p->d_date.year<<"-"<<p->d_date.month<<endl;

        print(p->left);
        print(p->right);
    }
    else return;
    
}
//返回字符串函数-输入节点-返回含有该节点下所有数据的字符串
std::string bsTree::getall(Node *p)
{
    std::string str="";
    if(p!=NULL)
    {
        str+=p->stu_name+" "+p->stu_number+" "+p->stu_sex+" "+p->phonenumber+" "+
        p->stu_address+" "+to_string(p->d_date.year)+" "+to_string(p->d_date.month)+"\n";

        str+=getall(p->left);
        str+=getall(p->right);
    }
    return str;
}

//查找函数-输入节点，输出节点指针和暗藏的父节点pr--查找的是学号
Node *bsTree::Search(Node d, Node* &pr)
{
    Node *p=root;pr=NULL;
    while(p!=NULL)
    {
        if(p->stu_number == d.stu_number) return p;
        else
        {
            pr=p;
            if(d.stu_number < p->stu_number)p=p->left;
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
    
    s=new Node();
    s->d_date.year=d.d_date.year;
    s->d_date.month=d.d_date.month;
    s->phonenumber=d.phonenumber;
    s->stu_address=d.stu_address;
    s->stu_name=d.stu_name;
    s->stu_number=d.stu_number;
    s->stu_sex=d.stu_sex;
    
    if(root==NULL)root=s; //如果是空树，根节点就是s
    else if(d.stu_number < pr->stu_number) pr->left=s;//key小于pr.key,
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
        p->stu_number=s->stu_number;
        p->d_date.year=s->d_date.year;
        p->d_date.month=s->d_date.month;
        p->phonenumber=s->phonenumber;
        p->stu_address=s->stu_address;
        p->stu_name=s->stu_name;
        p->stu_sex=s->stu_sex;
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

                                                                                        
#endif