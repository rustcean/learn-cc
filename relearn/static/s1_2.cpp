/**
 * @file s1_2.cpp
 * @author your name (you@domain.com)
 * @brief 对于static成员数据,private也可以在类外声明定义 
 * 
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
using namespace std;
class Apple
{
    static int i;
    public:
    void add(int x);
    int get(){return i;}
    Apple(){cout<<"nothing"<<endl;}
};
int Apple::i=0;//需要在类外对static进行声明定义,private也可以!!!

void Apple::add(int x){i+=x;}
int main()
{
    Apple obj1;
    Apple obj2;
    obj1.add(1);
    obj2.add(1);

    cout<<obj1.get()<<endl;
    
    return 0;
}