/**
 * @file p5_4.virtual.cpp
 * @author wnanqun
 * @brief继承: 
 * 
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
class A
{
    public:
    void vf()
    {cout<<"I come from class A"<<endl;}

};
class B:virtual public A{};
class C:virtual public A{};
class D:public B,public C{};
int main()
{
    D d;
    d.vf();// 出现二义性,前面的继承变成虚继承就不会出现二义性
    return 0;
}