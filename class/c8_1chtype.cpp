#include <iostream>
using namespace std;
class Complex
{
    double real;
    double imag;
    public:
    Complex(){real=0;imag=0;}
    Complex(double r,double i=0){real=r;imag=i;}
    //类型转换函数,只能作为成员函数,隐式调用,转换为普通类型的数据用
    operator double(){return real;}
};
int main()
{
    Complex c1(3,4),c2(5,-10),c3;
    double d;
    d=2.5+c1;
    cout<<d<<endl;//5.5
    d=2.5+c2;
    cout<<d<<endl;//7.5
    return 0;
}
