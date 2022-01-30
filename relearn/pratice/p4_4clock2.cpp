/**
 * 前++跟后++的重载
*/
#include <iostream>
using namespace std;
class Time
{
    public:
    Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}
    void operator++();//前++
    void operator++(int);// 括号中插入 int 表示后缀
    friend Time operator--(Time &t);//作为友元的前--
    friend Time operator--(Time &t,int);//作为友元的后--
    friend ostream&operator<<(ostream&out,Time &t);
    void showTime();
    private:
    int hour,minute,second;
};
void Time::showTime()
{cout<<"当前时间:"<<hour<<":"<<minute<<":"<<second<<endl;}
//重载
void Time::operator++()
{
    ++second;
    if(second>=60)
    {second-=60;minute+=1;}
    if(minute>=60)
    {minute-=60;hour+=1;}
    if(hour>=24)
    hour-=24;
}
void Time::operator++(int)
{
    second++;
    if(second>=60)
    {second-=60;minute+=1;}
    if(minute>=60)
    {minute-=60;hour+=1;}
    if(hour>=24)
    hour-=24;
}
Time operator--(Time &t)
{
    --t.second;
    if(t.second<0)
    {t.second+=60;t.minute-=1;}
    if(t.minute<0)
    {t.minute+=60;t.hour-=1;}
    if(t.hour<0)
    {t.hour+=24;}
    return t;
}
Time operator--(Time &t,int)
{
    t.second--;
    if(t.second<0)
    {t.second+=60;t.minute-=1;}
    if(t.minute<0)
    {t.minute+=60;t.hour-=1;}
    if(t.hour<0)
    {t.hour+=24;}
    return t;
}
ostream&operator<<(ostream&out,Time &t)
{
    out<<t.hour<<":"<<t.minute<<":"<<t.second;
    return out;
}
int main()
{
    Time t(23,59,59);
    ++t;
    t.showTime();
    cout<<t<<endl;
    t++;
    t.showTime();
    --t;
    t.showTime();
    t--;
    t.showTime();
    return 0;
}