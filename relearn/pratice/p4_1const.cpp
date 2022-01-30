/**const对象只能使用const成员函数,保证绝对不会改变值
 * const可用于参与对重载函数的区分
 * 
**/

#include <iostream>
using namespace std;
void display(const double &r);
class A
{
    public:
    A(int i,int j){x=i;y=j;}
    int getx()const{return x;}
    int gety(){return y;}
    void setx();
    void sety();
    //const区分成员重载函数
    void print();
    void print()const;
    private:
    int x,y;
};
void A::setx()
{
    cout<<"input x:";
    cin>>x;
}
void A::sety()
{
    cout<<"input y:";
    cin>>y;
}
void A::print()
{
    cout<<"普通调用"<<endl;
}
void A::print()const
{
    cout<<"常对象调用"<<endl;
    cout<<x<<y<<endl;
    // cout<<"改变x:"<<endl;
    // cin>>x;
    /*报错:no match for ‘operator>>’ (operand types are ‘std::istream’ 
    {aka ‘std::basic_istream<char>’} and ‘const int’)*/

}

int main()
{
    double d(9.5);
    display(d);
    A const a(3,4);//a是常对象,不能改值
    //a.setx()//错误,不能改值
    //a.gety();//虽然实际不会改值但是,编译器不知道,
    cout<<a.getx()<<endl;
    a.print();
    A b(4,3);
    b.print();
    return 0;
}
void display(const double &r)
{
    cout<<r<<endl;
}