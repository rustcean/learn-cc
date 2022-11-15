#include "Time.h"
#include <iostream>
using namespace std;

//两构造函数和析构函数
Time::Time(/* args */)
{ 
    this->hour=0;
    this->minute=0;
    this->second=0;
}
Time::Time(int h,int m,int s)
{
    this->hour=h;
    this->minute=m;
    this->second=s;
}
Time::~Time()
{}
//set函数
void Time::setT(int h,int m,int s)
{
    this->hour=h;
    this->minute=m;
    this->second=s;
}
void Time::Set()
{
    cout<<"输入时间(例:xx(时) xx(分) xx(秒) ): "<<endl;
    cin>>hour>>minute>>second;
}
//get函数
int Time::getH(){return this->hour;}
int Time::getM(){return this->minute;}
int Time::getS(){return this->second;}

//工具函数
void Time::Print()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
void Time::add(Time &t)
{
    hour=hour+t.hour;
    minute=minute+t.minute;
    second=second+t.second;

    minute=second/60+minute;
    second=second%60;
    hour=minute/60+hour;
    minute=minute%60;

}
void Time::minus(Time &t)
{
    hour=hour-t.hour;
    minute=minute-t.minute;
    second=second-t.second;

    while(second<0)
    {second+=60;minute-=1;}
    while(minute<0)
    {minute+=60;hour-=1;}
}

