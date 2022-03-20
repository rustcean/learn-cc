/**
 * @file p6_1allvirtual.cpp纯虚函数及其类
 * @author wnanqun
 * @brief 
 * @version 0.1
 * @date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;
class Figure
{
    protected:
    double x,y;
    public:
    void set(double i,double j)
    {x=i;y=j;}
    virtual void area()=0;//纯虚函数
};
class Trianle:public Figure
{
    public:
    void area()
    {
        cout<<"三角形,面积:"<<x*y*0.5<<endl;//继承了protected的内容
    }
};
class Rectrangle:public Figure
{
    public:
    void area()
    {
        cout<<"矩形,面积:"<<x*y<<endl;
    }
};
int main()
{
    Figure *p=NULL;
    Rectrangle r;
    Trianle t;
    t.set(10,20);
    p=&t;
    p->area();
    r.set(10,20);
    p=&r;
    p->area();
    Figure &rp=t;
    rp.area();
    rp=r;//引用不能被重新赋值
    rp.area();//输出矩形
   
    return 0;
    
}
