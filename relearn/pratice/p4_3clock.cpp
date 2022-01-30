/**学习:
 * 自动跳回上一行,并清除,再输出\033[1A和\033[K
 * sleep函数-默认1秒为单位,需要<unistd.h>库
*/


#include <iostream>//时钟
#include <unistd.h>//sleep函数
using namespace std;
//时钟类声明
class Clock
{
    public:
    Clock(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}//\r
    Clock(Clock &c);
    void setTime(int h,int m,int s);//设置时间
    void selftime();//自动计时,会在同一地方显示
    void showtime();//输出当前时间
    void change();//格式校准
    void operator()(int h,int m,int s);
    private:
    int hour,minute,second;
};
//函数实现:
Clock::Clock(Clock &c)
{hour=c.hour;minute=c.minute;second=c.second;}
void Clock::setTime(int h,int m,int s)
{hour=h;minute=m;second=s;}
void Clock::change()
{
    if(second>=60)
    {
        second-=60;
        minute+=1;
    }
    if(minute>=60)
    {
        minute-=60;
        hour+=1;
    }
    if(hour>=24)
    {
        hour=0;
    }
}
void Clock::operator()(int h,int m,int s)
{hour=h;minute=m;second=s;}
void Clock::selftime()
{
    while(1)
    {
        printf("\033[1A");//回到上一行
        printf("\033[K");//清除该行
        sleep(1);
        cout<<hour<<":"<<minute<<":"<<second<<endl;
        second+=1;
        change();
    }
}
void Clock::showtime()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
//主函数:
int main()
{
    Clock c1(0,59,56);
    c1(10,10,10);
    c1.showtime();
    cout<<endl;
    c1.selftime();
    
    return 0;
}