/**
 * 继承的顺序学习,先基类再组合,先声明的先,再按前后顺序
*/
#include <iostream>
using namespace std;
class A
{
    int x;
    public:
    A(int i=0){x=i;cout<<"A..."<<x<<endl;}
};
class B
{
    int y;
    public:
    B(int i)
    {y=i;cout<<"B..."<<y<<endl;}
};
class C
{
    int z;
    public:
    C(int i)
    {z=i;cout<<"C..."<<z<<endl;}
};
class D:public B//第一个call
{
    public:
    C c1,c2;//第二第三
    A *a1=new A(10);
    A a0,a4;//第四五
    D():a4(4),c2(2),c1(1),B(1)//第6
    {cout<<"D...5"<<endl;}
};
int main()
{
    D d;
    return 0;
}

