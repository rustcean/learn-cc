#include <iostream>
using namespace std;
class Complex
{
    double real;
    double imag;
    public:
    Complex(){real=0;imag=0;}
    //转换构造函数,将普通类型的数据转换为class类
    //长的像有参数的构造函数,如下面这一个
    Complex(double r){real=r;imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    operator double(){return this->real;}
    //将加号用友元函数定义,可以交换律
    friend Complex operator+(Complex c1,Complex c2);//加号重载
    friend ostream& operator<<(ostream &out,Complex&c);//输出流重载
};
Complex operator+(Complex c1,Complex c2)
{
    
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
//    Complex re;
//     re.real=c1.real+c2.real;
//     re.imag=c1.imag+c2.imag;
//     return re;

ostream & operator<<(ostream&out,Complex&c)
{
    cout<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
    return out;
}
int main()
{
    Complex  c1(3,4),c2(5,-10),c3;
    c3=c1+2.5;
    cout<<c3;
    c3=2.5+c1;
    cout<<c3;//交换律
    return 0;
}