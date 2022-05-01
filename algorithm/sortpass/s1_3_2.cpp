//size_t是为了方便系统之间的移植而定义的,无符号整形,不会小于0
//size_t 的数据类型为unsigned long (m)
//有一个需要注意的小问题:
#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    size_t t=1;
    cout<<typeid(t).name()<<endl;//m --unsigned long类型
    unsigned long d=-1;
    cout<<d<<endl;
    cout<<typeid(d).name()<<endl;//m
    
    int z=-1;
    if(z<t)
    {cout<<"I am in trouble"<<endl;}
    else{cout<<"there is the answer:z="<<z<<endl;}
    /*此时不能进入if语句
    原因:
    因为size_t类型是无符号，int型是有符号,
    编译器把有符号的z转换成了无符号的z，也就变成了4294967295,
    但当int unsigned为0或正数时,则可以
    */
    int a=0;
    long long x=-1;
    cout<<typeid(x).name()<<endl;//x
    cout<<typeid(int).name()<<endl;
    cout<<typeid(char).name()<<endl;
    cout<<typeid(string).name()<<endl;
    cout<<typeid(long).name()<<endl;
    cout<<typeid(unsigned long long).name()<<endl;
    cout<<typeid(unsigned int).name()<<endl;
    cout<<typeid(bool).name()<<endl;
    cout<<typeid(ssize_t).name()<<endl;
    return 0;
}

/*
x --long long
y --unsigned long long
l --long  --ssize_t
m --unsigned long  --size_t
i --int
j --unsigned int
c --char
b --bool
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE --string

 
*/


