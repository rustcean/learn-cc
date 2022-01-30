/**
 * @file h10_4file.cpp
 * @author your name (you@domain.com)
 * @brief 人员管理保存读取保存
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;
struct person
{
    char name[20];
    char work[25];
    int age;
    char sex;
};
int main()
{
    int i;
    person p[2]=
    {
        "Wang","老师",25,'f',
        "Li","老师",28,'m'
    };
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::binary);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        abort();//什么函数
    }
    for(i=0;i<2;i++)
    {
        outfile.write((char *)&p[i],sizeof(p[i]));
    }
    outfile.close();
    ifstream infile("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::binary);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        abort();
    }
    for(i=0;i<3;i++)
    infile.read((char*)&p[i],sizeof(p[i]));
    infile.close();
    for(i=0;i<2;i++)
    {
        cout<<"No."<<i+1<<endl;
        cout<<"name:"<<p[i].name<<endl;
        cout<<"work:"<<p[i].work<<endl;
        cout<<"age:"<<p[i].age<<endl;
        cout<<"sex:"<<p[i].sex<<endl;
    }
    return 0;




}