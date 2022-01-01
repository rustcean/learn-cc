#include <iostream>
using namespace std;
class Time
{
    public:
    Time (int h,int m,int s):hour(h),minute(m),sec(s){}
    friend class Date;//声明为友元类
    int hour;
    int minute;
    int sec;
};
class Date
{
    public:
    Date(int m,int d,int y):month(m),day(d),year(y){}
    void display(Time &a); 
    private:
    int month;
    int day;
    int year;
};
void Date::display(Time &a)
{
    cout<<month<<":"<<day<<":"<<year<<endl;
    cout<<a.hour<<":"<<a.minute<<":"<<a.sec<<endl;
    //这里只能用这样的形式来写可是这样不久跟友元函数一样了咩
}
int main()
{
    Time t1(12,30,12);
    Date d1(10,24,2008);
    d1.display(t1);
    return 0;

}
