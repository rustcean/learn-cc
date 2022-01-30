//友元重载练习
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
    //operator double(){return this->real;}//会使函数出现二义性
    //将加号用友元函数定义,可以交换律
    friend Complex operator+(Complex c1,Complex c2);//加号重载
    friend Complex operator-(Complex c1,Complex c2);//减号重载
    friend Complex operator*(Complex c1,Complex c2);//乘号重载
    friend Complex operator/(Complex c1,Complex c2);//除号重载
    friend ostream& operator<<(ostream &out,Complex &c);//输出流重载
    friend istream& operator>>(istream &in,Complex &c);//输入重载
};
Complex operator+(Complex c1,Complex c2)
{
    
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator-(Complex c1,Complex c2)
{
    return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
Complex operator*(Complex c1,Complex c2)
{
    Complex re;
    re.imag=c1.real*c2.real-c1.imag*c2.imag;
    re.imag=c1.real*c2.imag+c1.imag*c2.real;
    return re;
}
Complex operator/(Complex c1,Complex c2)//除号比较难理解
{
    double x;
    x=1/(c2.real*c2.real+c2.imag*c2.imag);
    Complex re;
    re.real=x*(c1.real+c2.real+c1.imag*c2.imag);
    re.imag=x*(c1.imag*c2.real-c1.real*c2.imag);
    return re;
}

//    Complex re;
//     re.real=c1.real+c2.real;
//     re.imag=c1.imag+c2.imag;
//     return re;

ostream & operator<<(ostream&out,Complex&c)
{   
    if(c.imag>0)
    out<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
    else if(c.imag==0)
    out<<c.real<<endl;
    else if(c.imag<0)
    out<<"("<<c.real<<c.imag<<"i)"<<endl;
    return out;
}
istream&operator>>(istream &in,Complex &c)
{
    cout<<"输入实数部分:";
    in>>c.real;
    cout<<"输入虚数部分:";
    in>>c.imag;
    return in;
}
int main()
{
    Complex  c1(3,4),c2(5,-10),c3;
    c3=c1+2.5;//
    cout<<c3;
    c3=2.5+c1;//
    cout<<c3;//交换律
    c3=c3+c1;
    cout<<c3;
    c3=c1-c2;
    cout<<c3;
    c3=c3/c1;
    cout<<c3;
    c3=c3*c2;
    cout<<c3;cout<<c3;

    cin>>c3;
    cout<<c3;
    
    return 0;
}
/*
Complex operator+(Complex b);
friend Complex operator+(Complex a,Complex b)
*/