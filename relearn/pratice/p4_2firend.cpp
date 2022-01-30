#include <iostream>
#include <cmath>
using namespace std;
//Point类的声明:
class Point
{
    public:
    Point(int a=0,int b=0):x(a),y(b){}//构造函数不能作为友元
    ~Point(){cout<<"called"<<endl;}
    //friend int getx(){return x;}//友元不是成员函数
    int getx()const{return x;}
    int gety()const{return y;}
    //friend float Distance(Point &a, Point &b)const;
    //不能用const因为不是成员函数,所以没有所谓的内容变量--cannot have cv-qualifier
    friend float Distance(Point &a, Point &b);
    friend void setPoint(Point &a);
    private:
    int x,y;
};
//Point类的函数:
float Distance(Point &a,Point &b)
{
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
void setPoint(Point &a)
{
    cout<<"输入x:";
    cin>>a.x;
    cout<<"输入y:";
    cin>>a.y;
}

class B
{
    public:
    void Display(){cout<<z<<endl;}
    private:
    int z;
    
};
int main()
{   
    Point A(2,3);
    Point B;
    setPoint(B);
    cout<<Distance(A,B)<<endl;
    
    return 0;
}
