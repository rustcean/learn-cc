/**
 * @file p5_3jurisdiction.cpp
 * @author wnanqun
 * @brief 1.基类的protected成员:类的使用者不可访问
 * 2.protected继承:protected数据仍然为protected,public变成protected,所以类使用者不能访问
 * 3.私有继承:所有都变成私有,原来的私有不可访问,公有则变私有,仅派生成员可访问
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
class Base
{
    int x;
    public:
    void setx(int n){x=n;}
    int getx(){return x;}
    void showx(){cout<<x<<endl;}
};
class Derived:private Base
{
    int y;
    public:
    void sety(int n){y=n;}
    void sety(){y=getx();}
    void showy(){cout<<y<<endl;}
};
int main()
{
    Derived obj;
    // obj.setx(10);//错误类外不可访问
    obj.sety(20);
    obj.showy();
    return 0;
}
