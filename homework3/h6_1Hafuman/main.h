#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define leafNum 27
#define Maxnum 60
using namespace std;
//节点
struct Node
{
    int key; //记录频率
    std::string data;//记录字符
    int lchild, rchild, parent;//记录父节点,子节点的值
};
//存储每个字符及其哈夫曼编码
typedef struct
{
    std::string ch;   //字符
    std::string code; //编码
} HFCharCode;
HFCharCode HCD[28]; //哈夫曼编码结构体
//哈夫曼树
struct HFTree
{
    Node elem[Maxnum];
    int num; //大小
    int root;
    void createHFTree(std::string ch[], int fr[], int n);
    void printHFTree();
    std::string printF();                   //返回表格内容
    void CreateHFCode();                    //编码表
    std::string Encodestr(std::string str); //编码
    std::string Decode(std::string );//解码
};
void HFTree::createHFTree(std::string ch[], int fr[], int n)
{
    int i, k, s1, s2;
    int min1, min2;
    for (i = 0; i < n; i++)
    {
        elem[i].data = ch[i];
        elem[i].key = fr[i];
    }
    for (i = 0; i < Maxnum ;i++)
    {
        elem[i].parent = elem[i].lchild = elem[i].rchild = -1;
    }
    for (i = n; i < 2 * n - 1; i++)
    {
        min1 = min2 = 999;//先放到最大
        s1 = s2 = -1;
        for (k = 0; k < i; k++)
        {
            // cout<<elem[k].parent<<" ";
            if (elem[k].parent == -1)//当他们还未被接上树
                if (elem[k].key < min1)
                {
                    min2 = min1;
                    s2 = s1;
                    min1 = elem[k].key;
                    s1 = k;
                }
                else if (elem[k].key < min2)
                {
                    min2 = elem[k].key;
                    s2 = k;
                }
        }
        // cout<<endl;
        // cout<<i<<" "<<s1<<" "<<s2<<endl;
        elem[s1].parent = elem[s2].parent = i; //构造子树
        elem[i].lchild = s1;//插入
        elem[i].rchild = s2;
        elem[i].key = elem[s1].key + elem[s2].key;
    }
    num = n;
    root = 2 * n - 2;

}
//输出树
void HFTree::printHFTree()
{
    for (int i = 0; i < 2 * num - 1; i++)
    {
        std::string value = i < num ? elem[i].data : "--";
        if (i < 10)
            cout << " ";
        cout << i << ":" << value;
        if (elem[i].key < 10)
            cout << " ";
        cout << " " << elem[i].key;
        if (i < num)
        {
            cout << " " << elem[i].lchild << " " << elem[i].rchild << " ";
        }
        else
        {
            cout << " " << elem[i].lchild << " " << elem[i].rchild << " ";
        }
        cout << elem[i].parent << endl;
    }
    cout << "root=" << root << endl;
}
//直接输出elem表
std::string HFTree::printF()
{
    string str="";
    for (int i = 0; i <= root; i++)//顺便把根输出
    {
        // cout << elem[i].parent << " " << elem[i].key << " " << elem[i].data << elem[i].lchild << elem->rchild << endl;
        string str1=to_string(elem[i].parent)+" "+to_string(elem[i].key)+" "+elem[i].data+" "+to_string(elem[i].lchild)+" "+to_string(elem->rchild)+"\n";
        str+=str1;
    }
    return str;
}
//建立哈夫曼表
void HFTree::CreateHFCode()
{
    int i, j;
    for (i = 0; i < leafNum; i++)
    {
        j = i;
        HCD[i].code = "";
        HCD[i].ch = elem[j].data;
        while (elem[j].parent!= root) //当不是根节点
        {
            // cout<<j<<endl;
            if (elem[elem[j].parent].lchild == j) //双亲节点的左孩子
            {
                HCD[i].code += "0"; //加上字符0
            }
            else                    //是右孩子
                HCD[i].code += "1"; //加上字符1
            j = elem[j].parent;     //往上遍历
            //  cout<<j<<endl;
        }
        //还得再做一遍
        if (elem[elem[j].parent].lchild == j) //双亲节点的左孩子
        {
            HCD[i].code += "0"; //加上字符0
        }
        else                    //是右孩子
            HCD[i].code += "1"; //加上字符1
        //倒序
        reverse(HCD[i].code.begin(),HCD[i].code.end());
        // cout << HCD[i].code << endl; //输出对应的表--检验
    }

}
//编码函数
std::string HFTree::Encodestr(std::string str)
{
    int len = str.length();
    std::string str_for_in = "";
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < leafNum; j++)
        {
            string a = "";
            a.append(1, str[i]);
            if (HCD[j].ch.compare(a) == 0)
            {
                str_for_in += HCD[j].code;
                // cout<<a<<"  "<<HCD[j].ch<<"  "<<HCD[j].code<<endl;//没问题
                
            }
        }
    }
    // cout << "编码结果:" << endl;
    // cout << str_for_in << endl;
    return str_for_in;
}

//解码函数
std::string HFTree::Decode(std::string str)
{
    int k=root;//根节点
    int len=0,i=0;
    std::string result="";
    while(i<str.length()){
        if(str[i]=='0')//往左边走
        {
            k=elem[k].lchild;
        }
        else if(str[i]=='1')//往右边走
        {
            k=elem[k].rchild;
        }
        else
        {
            cout<<"出错,密文中只能含有1或0!"<<endl<<endl;
            exit(-1);
        }
        if(elem[k].lchild==-1 && elem[k].rchild==-1)//找到了
        {
            result+=string(elem[k].data);
            k=root;
        }
        i++;
    }
    if(k==root)
    {
        // cout<<"结果: "<<result<<endl;
        return result;
    }
    cout<<"出错!部分密文无法解密!"<<endl<<endl;
    return result;
}


#endif