#include "c1_2Date.cpp"
using namespace std;
class Date1:public Date
{
    public:
    Date1(int y=1900, int m=1,int d=1):Date(y,m,d){}
    int leap_year(int now_year);//判断润年 
    int sum_date();//计算一个日期的绝对值天数
    friend int diff(Date1 ,Date1);//计算两个日期的差值
    void charge();//判断日期设置是否合理
    void change();//将日期改为正常格式的日期
};
//以下为函数实现
//判断润年 
int Date1::leap_year(int now_year)
{
    if((now_year%4==0&&now_year%100!=0)||(now_year%400==0))
    return 1;
    return 0;
}
//计算一个日期的绝对值天数
int Date1::sum_date()
{
    int m[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(get_year()))
    {m[2]++;}
    int result=0;
    for(int i=0;i<get_year();i++)
    {
        result+=365;
        if(leap_year(i))
        result++;
    }
    for(int i=1;i<get_month();i++)
    {
        result+=m[i];
    }
    result+=get_day();
    return result;
}
//计算两个日期的差值
int diff(Date1 d1,Date1 d2)
{
    int result=d1.sum_date();
    result-=d2.sum_date();
    if(result<0)
    {result=-result;}
    return result;
}
//判断日期设置是否合理
void Date1::charge()
{
    int months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(get_year()))
    { months[2]=29;}
    if(get_month()<0||get_month()>12)
    {cout<<"input month error"<<endl;}
    if(get_month()>=1&&get_month()<=12)
    {
        if(months[get_month()]<get_day()||get_day()<=0)
        cout<<"input day error"<<endl;
    }
}
//将日期改为正常格式的日期
void Date1::change()
{
    int months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(get_year()))
    { months[2]=29;}
    while(get_day()>months[get_month()])
    {
        set_day(get_day()-months[get_month()]);
        set_month(get_month()+1);
        if(get_month()>12)
        {
            set_month(get_month()-12);
            set_year(get_year()+1);
        }
    }
    while(get_day()<0)
    {
        if(get_month()>1)
        {
            set_day(get_day()+months[get_month()-1]);
            set_month(get_month()-1);
            if(get_month()<=1)
            {
                set_year(get_year()-1);
                set_month(get_month()+12);
            }
        }
        if(get_month()<=1)
        {
            set_year(get_year()-1);
            set_month(get_month()+11);
            set_day(get_day()+months[get_month()]);
        }
    }
}


//主函数内容
int main()
{
    Date1 d1(2020,10,-1103);
    d1.charge();
    d1.change();
    cout<<d1.get_year()<<":"<<d1.get_month()<<":"<<d1.get_day()<<endl;
    Date1 d2;
    int x=diff(d1,d2);
    cout<<d2.get_year()<<":"<<d2.get_month()<<":"<<d2.get_day()<<endl;
    cout<<"相差天数:"<<x<<endl;
    return 0;
}






