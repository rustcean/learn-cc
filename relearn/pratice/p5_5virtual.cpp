/**
 *  先调用虚基类的构造函数，再调用非虚基类的构造函数 
 * 若同一层次中包含多个虚基类,这些虚基类的构造函数按
 * 它们的说明的次序调用 若虚基类由非基类派生而来,则仍
 * 然先调用基类构造函数,再调用派生类构造函数 
 * 虚拟继承:虚基类则由最终派生类的构造函数负责初始化
*/
#include <iostream>
using namespace std;
class A
{
    int a;//构造函数并没有对a进行赋值
    public:
    A(){cout<<"Constructing A"<<endl;}
};
class B
{
    public:
    B(){cout<<"Constructing B"<<endl;}
};
class B1:virtual public B,virtual public A
{
    public:
    B1(int i){cout<<"Constructing B1"<<endl;}
};
class B2: public A,virtual public B//设置为virtual则会被B1的给virtual掉,
{
    public:
    B2(int j){cout<<"Constructing B2"<<endl;}//不需要对基类赋值所以j并没有实际作用
};
class D:public B1,public B2
{
    public:
    D(int m,int n):B1(m),B2(n)
    {cout<<"Constructing D"<<endl;}
    A a;
};
int main()
{
    D a(1,2);
    return 0;
}
/*结果:
Constructing B
Constructing A
Constructing B1
Constructing A
Constructing B2
Constructing A
Constructing D

*/