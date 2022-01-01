#include <iostream>
using namespace std;
class Time
{
    public:
    Time(int ,int,int );
    int hour;
    int minute;
    int sec;
    void put_time();
};
Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    sec=s;
}
void Time::put_time()
{
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
int main()
{
    Time t1(10,13,56);
    int *p1=&t1.hour;//指向变量某个特征的指针
    cout<<*p1<<endl;
    t1.put_time();
    Time *p2=&t1;//指向变量的指针
    p2->put_time();
    void(Time::*p3)();
    p3=&Time::put_time;//指向函数的指针
    (t1.*p3)();
    return 0;
}