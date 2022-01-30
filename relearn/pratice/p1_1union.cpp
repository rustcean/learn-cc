/**
 * @file p1_1union.cpp
 * @author your name (you@domain.com)
 * @brief 联合体学习.cpp
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
union myun
{
    struct {int x;int y;int z;}u;
    int k;
    int l;
}a;
int main()
{
    a.u.x=4;
    a.u.y=5;
    a.u.z=6;
    a.k=1;//覆盖第一个int空间
    a.l=0;//覆盖第一个int和k的空间
    cout<<"a.u.x:"<<a.u.x<<endl;//0
    cout<<"a.u.y:"<<a.u.y<<endl;//5
    cout<<"a.u.z:"<<a.u.z<<endl;//6
    cout<<"a.k:"<<a.k<<endl;//0
    cout<<"a.l:"<<a.l<<endl;    //0
    return 0;
}
