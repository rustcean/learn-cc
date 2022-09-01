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
    double getdis(Point &X,Point &Y)//距离函数
    {return sqrt((X.p_x-Y.p_x)^2+(X.p_y-Y.p_y)^2);}
};

class Circle
{
    private:
    int r;
    public :
    int setR(int R)
    {r=R;return 0;}
    int getR()//?
    {return r;}
};
int main()
{
    Circle l1;
    Circle l2;
    cout<<"输入x1,y1,x2,y2"<<endl;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int r1,r2;
    cout<<"输入r1,r2:";
    cin>>r1>>r2;
    Point p1,p2;
    p1.setxy(a,b);
    p2.setxy(c,d);
    l1.setR(r1);
    l2.setR(r2);

    double k1;
    k1=p1.getdis(p1,p2);
    cout<<"距离: "<<k1<<endl;

    int s1,s2;
    s1=abs(l1.getR()-l2.getR());
    s2=l1.getR()+l2.getR();

    if(k1>=s1&&k1<=s2)
    {
        cout<<"yes"<<endl;
    }
    else    cout<<"no"<<endl;
    return 0;
}
