/*
*继承的练习
*/
#include <iostream>
using namespace std;
class Point
{
    int x,y;
    public:
    Point(int a,int b)
    {
        x=a;y=b;
        cout<<"constructing point("<<x<<","<<y<<")"<<endl;
    }
};
class Line:public Point
{
    protected:
    int len;
    public:
    Line(int a,int b,int i):Point(a,b)
    {
        len=i;
        cout<<"constructing Line,len ..."<<len<<endl;
    }
};
int main()
{
    Line l1(1,2,3);
    return 0;
}
