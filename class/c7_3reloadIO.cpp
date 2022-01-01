#include <iostream>
using namespace std;
class Complex
{
    public:
    Complex(int r=0,int i=0);//默认构造函数
    Complex operator+(Complex &c);//重载复数+
    Complex operator-(Complex &c);//重载复数-
    Complex operator+(int c);//重载复数加整数
    friend ostream& operator<<(ostream&,Complex&);//重载>>
    friend istream& operator>>(istream&,Complex&);//重载<<
    private:
    int real;//复数的实数部分
    int it;//虚部
};
Complex::Complex(int r,int i){real=r;it=i;}
Complex Complex::operator+(Complex& c)
{
    Complex i;
    i.real=real+c.real;
    i.it=it+c.it;
    return i;
}
Complex Complex::operator-(Complex& c)
{
    Complex i;
    i.real=real-c.real;
    i.it=it-c.it;
    return i;
}
Complex Complex::operator+(int a)
{
    Complex i;
    i.real=i.real+a+real;
    i.it=it;
    return i;
}
ostream& operator<<(ostream &o,Complex &c)
{
    o<<"("<<c.real<<"+"<<c.it<<"i)";
    return o;
}
istream& operator>>(istream&i,Complex&c)
{
    i>>c.real;      
    i>>c.it;
    return i;
}
int main()
{
    Complex c1(2,3);
    cout<<"c1="<<c1<<endl;
    Complex c2;
    cout<<"c2="<<c2<<endl;
    cout<<"请输入从c2:";
    cin>>c2;
    cout<<"c2="<<c2<<endl;
    Complex c3=c1+c2;
    cout<<"c1+c2="<<c3<<endl;
    Complex c4=c1-c2;
    cout<<"c1-c2="<<c4<<endl;
    c1=c1+2;
    cout<<"c1+2="<<c1<<endl;
    return 0;
}