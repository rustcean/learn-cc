#include <iostream>
using namespace std;
class Time
{
    public:
    Time(int,int,int);
    int hour;
    int minute;
    int sec;
};
Time::Time(int h,int m,int s):hour(h),minute(m),sec(s){}
void fun(Time &t)//加了const 之后,确实t的值不能该,所以下面的内容只能是非赋值类
{
    t.hour=18;
}
int main()
{
    Time t1(10,13,56);
    fun(t1);
    cout<<t1.hour<<endl;//答案:18
    return 0;
}
