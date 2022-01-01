#include <iostream>
#include <cmath>
using namespace std;

int leap_year(int now_year)//判断润年 
{
    if((now_year%4==0&&now_year%100!=0)||(now_year%400==0))
    return 1;
    return 0;
}
class Date
{
    int day;
    int month;
    int year;
    public:
    Date(){day=1;month=1;year=1900;}
    Date(int y,int m=1,int d=1);//不能参数都有,会与默认参数冲突 
    ~Date(){cout<<"struct called"<<endl;}//析构函数
    void get_day();//输出天
    void get_year();//输出年
    void get_month();//输出月
    void get_date();//输出日期
    int getdays();//求出每个日期的绝对值,为-重载做准备
    friend int operator-( Date &, Date&);//重载减号
    Date operator|(Date &);//重载提取符,不符合规范的概念,但感觉这样会跟好
    friend ostream & operator<<(ostream &,Date&);//重载输出流
    friend istream & operator>>(istream&,Date&);//重载输入流
    void charge();//用来判断输入的日期是否符合格式
};
Date::Date(int y,int m,int d)
{
    day=d;
    month=m;
    year=y;
}
void Date::get_day()
{
    cout<<"day is "<<day<<endl;
}
void Date::get_month()
{
    cout<<"month is "<<month<<endl;
}
void Date::get_year()
{
    cout<<"year is "<<year<<endl;
}
void Date::get_date()//输出日期
{
    cout<<"date is "<<year<<":"<<month<<":"<<day<<endl;
}
//计算两个日期之间的差值--
int Date::getdays()//算出日期的绝对值
    {
    int m[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(year))
    {m[2]++;}
    int result=0;
    for(int i=0;i<year;i++)
    {
        result+=365;
        if(leap_year(i))
        result++;
    }
    for(int i=1;i<month;i++)
    {
        result+=m[i];
    }
    result+=day;
    result=abs(result);
    return result;
    }
int operator-( Date &d1, Date &d2)
{
    int result=d1.getdays()-d2.getdays();
    return result;
}
ostream & operator<<(ostream &out,Date&d)
{
    out<<d.year<<":"<<d.month<<":"<<d.day;
    return out;
}
istream& operator>>(istream&in,Date&d)
{
    cout<<"input year:";
    in>>d.year;
    cout<<"input month:";
    in>>d.month;
    cout<<"input day:";
    in>>d.day;
    return in;
}
Date Date::operator|(Date &d)
{
    Date result;
    result.year=year>d.year?year:d.year;
    result.day=day>d.day?day:d.day;
    result.month=month>d.month?month:d.month;
    return result;
}
void Date::charge()
{
    int months[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||(year%400==0))
    { months[2]=29;}
    if(month<0||month>12)
    {cout<<"input month error"<<endl;}
    if(month>=1&&month<=12)
    {
        if(months[month]<day)
        cout<<"input day error"<<endl;
    }
}

int main()
{
    Date d1(2020,9,1);
    Date d2(2020,10,1);
    Date d;
    cin>>d;
    d.charge();
    cout<<d;
    d=d1|d2;
    cout<<d1<<"|"<<d2<<"=";
    cout<<d;
    d1.get_day();
    d1.get_month();
    d1.get_year();
    int a=d1-d2;
    cout<<a<<endl;
    
}    

/*
int leap_year(int now_year)
    {
        if((now_year%4==0&&now_year%100!=0)||(now_year%400==0))
        return 1;
        return 0;
    }

date& operator-(int n)
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(leap_year(this->_year))
        {months[1]=29;}
        int n_cor=abs(n);
        this->_day=this->_day-n_cor;
        //一个循环
        while(this->_day<=0)
        {
            this->_month-=1;
            if(this->_month<=0)
            {
                this->_year-=1;
                if(leap_year(this->_year))
                {months[1]=29;}
                else {months[1]=28;}
                this->_month=12;
            }
            this->_day=this->_day+months[this->_month-1];
        }
        return *this;
    }


*/



