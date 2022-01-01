#include <iostream>
using namespace std;
class Time
{
    int hour;
    int minute;
    int second;
    public:
    Time();
    Time(int h,int m,int s );
    int get_hour();                     //hour获取
    int get_minute();                   //minute获取
    int get_second();                   //second获取
    void getin_hour();                  //hour外部输入
    void getin_minute();                //minute外部输入
    void getin_second();                //second外部输入
    void set_hour(int h);               //hour内部设置
    void set_minute(int m);             //minute内部设置
    void set_second(int d);             //second内部设置
};

//function reach
Time::Time()
{
    hour=0;
    minute=0;
    second=0;
}
Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    second=s;
}
int Time::get_hour(){return hour;}
int Time::get_minute(){return minute;}
int Time::get_second(){return second;}
void Time::getin_hour()
{
    cout<<"please input hour:";
    cin>>hour;
}
void Time::getin_minute()
{
    cout<<"please input minute:";
    cin>>minute;
}
void Time::getin_second()
{
    cout<<"please input second:";
    cin>>second;
}
void Time::set_hour(int h){hour=h;}
void Time::set_minute(int m){minute=m;}
void Time::set_second(int s){second=s;}

//以下为测试
/*
int main()
{
    Time t1(10,20,30);
    Time t2;
    cout<<t1.get_hour()<<":"<<t1.get_minute()<<":"<<t1.get_second()<<endl;
    cout<<t2.get_hour()<<":"<<t2.get_minute()<<":"<<t2.get_second()<<endl;
    t1.getin_hour();
    t1.getin_minute();
    t1.getin_second();
    t2.set_hour(10);
    t2.set_minute(12);
    t2.set_second(0);
    cout<<t1.get_hour()<<":"<<t1.get_minute()<<":"<<t1.get_second()<<endl;
    cout<<t2.get_hour()<<":"<<t2.get_minute()<<":"<<t2.get_second()<<endl;
    return 0;
}
*/