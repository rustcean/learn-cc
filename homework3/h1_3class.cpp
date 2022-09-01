//Point--Circle
#include <iostream>
#include "math.h"
using namespace std;

class Point
{
    public:
    int p_x;
    int p_y;
    Point(int x=0, int y=0)
    {p_x=x;p_y=y;}
    int setxy(int x,int y)//设置函数
    {p_x=x;p_y=y;return 0;}
    double getdis(Point &Y)//距离函数
    {return sqrt((p_x-Y.p_x)^2+(p_y-Y.p_y)^2);}
};

class Circle :public Point
{
    private:
    int c_r;
    public:
    Circle(int x,int y,int r):Point(x,y),c_r(r){}
    int setr(int r)
    {c_r=r;return 0;}
    int charge(Circle &Y);
};
int Circle::charge(Circle &Y)
{
    
    cout<<Point::getdis(Y);
    return 0;
}

int main()
{
    Circle c1(1,1,1);
    Circle c2(1,3,1);
    int length=c1.charge(c2);
    cout<<length<<endl;
    return 0;
}







