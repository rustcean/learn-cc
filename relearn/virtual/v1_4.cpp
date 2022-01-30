
#include<iostream>
using namespace std;
class A{};
class B
{
    public:
    char b;
    virtual void fun(){};
    static int c;
    static int d;
};
class C:public A
{};
class D
{
    public:
    virtual void fun(){};
    virtual void fun1(){};
    virtual void fun2(){};
};
int main()
{
    cout<<"类的大小至少有1-vptr(32位操作系统4字节，64位操作系统 8字节):"<<endl;
    cout<<sizeof(A)<<endl<<endl<<endl;//1
    cout<<"字节对齐,静态变量不影响类的大小"<<endl;
    cout<<sizeof(B)<<endl<<endl<<endl;//16
    cout<<"仅仅将A继承而没有其他元素的类,会继承基的指针,所以大小不变"<<endl;
    cout<<sizeof(C)<<endl;//1
    cout<<"虚函数不占大小:"<<endl;
    cout<<sizeof(D)<<endl;//8
    return 0;
}