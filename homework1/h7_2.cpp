#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
class date
{
    protected:
    int _year;
    int _month;
    int _day;
    public:
    void SetYear(int year){_year=year;}
    void SetMonth(int month){_month=month;}
    void SetDay(int day){_day=day;}
    date(int year=1700,int month=1,int day=1)
    {
        _year=year;
        _month=month;
        _day=day;
    }
    date(date&d)
    {
        _year=d._year;
        _month=d._month;
        _day=d._day;
    }
    int leap_year(int now_year)
    {
        if((now_year%4==0&&now_year%100!=0)||(now_year%400==0))
        return 1;
        return 0;
    }
    friend ostream& operator<<(ostream&out,date&d)
    {
        out<<d._year<<":"<<d._month<<":"<<d._day<<endl;
        return out;
    }
    friend istream& operator>>(istream&in,date &d)
    {
        int year;int month;int day;//感觉可以直接对那些值进行输入值,之后再来
        cout<<"input year month day:";
        cin>>year>>month>>day;
        d.SetYear(year);
        d.SetMonth(month);
        d.SetDay(day);
        return in;
    }//用于输入日期
    date & operator=(date &d)
    {   
        _year=d._year;
        _month=d._month;
        _day=d._day;
        return *this;
    }//赋值构造函数
    date&operator+(int n)
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if (leap_year(this->_year))
        months[1]=29;
        int n_cor=abs(n);//没看懂的函数
        this->_day+=n_cor;
        //一个循环,重点
        while(this->_day>months[this->_month-1])
        {
            this->_day-=months[this->_month-1];
            this->_month+=1;
            if(this->_month>12)
            {
                this->_month=1;
                this->_year+=1;
                if(leap_year(this->_year))
                {
                    months[1]=29;
                }
                else months[1]=28;
            }
        }
        return *this;
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

    date& operator++()
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(leap_year(this->_year))
        {
            months[1]=29;
        }
        this->_day++;
        if(this->_day>months[this->_month-1])
        {
            this->_day=this->_day-months[this->_month-1];
            this->_month+=1;
            if(this->_month>12)
            {
                this->_month=1;
                this->_year++;
            }
        }
        return *this;
    }

    date& operator--()
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(leap_year(this->_year))
        {months[1]=29;}
        this->_day-=1;
        if(this->_day<=0)
        {
            this->_day=this->_day+months[this->_month-1];
            this->_month-=1;
            if(this->_month<=0)
            {
                this->_month=12;
                this->_year-=1;
            }
        }
        return *this;
    }

    int operator-(date &d)
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(leap_year(min(this->_year,d._year)))
        {
            months[1]=29;
        }
        int d_days=d._day;
        int this_days=this->_day;
        if(this->_year!=d._year)//两者不在同一年
        {
            int min_year = min(this->_year,d._year);//获得二者最小的年份
            int now_year;
            for(now_year=min_year;now_year<this->_year;now_year++)
            {
                this_days+=365+leap_year(now_year);
            }
            for(int m=1;m<this->_month;m++)
            {
                this_days+=months[m];
            }
            for(now_year=min_year;now_year<d._year;now_year++)
            {
                d_days+=365+leap_year(now_year);
            }
            for(int m=1;m<d._month;m++)
            {
                d_days+=months[m];
            }
        }
        else//在同一年 
        {
            for(int m=1;m<this->_month;m++)
            {
                this_days+=months[m];
            }
            for(int m=1;m<d._month;m++)
            {
                d_days+=months[m];
            }
        }
        return abs(d_days-this_days);
    }//重载-运算符,计算两日器相差的天数

    ~date(){cout<<"called"<<endl;}
};
//继承date类,增加时分秒
class Time:public date
{
    private:
    int _hour;
    int _minute;
    int _second;
    public:
    Time(int year,int month,int day,int hour=1,int min=1,int second=1):
    date(year,month,day),_hour(hour),_minute(min),_second(second){}
    void outtime()
    {
        cout<<"time is "<<endl;
        cout<<_year<<"-"<<_month<<"-"<<_day<<"-";
        cout<<_hour<<"-"<<_minute<<"-"<<_second;
        cout<<endl;
    }//输出函数
    Time&Addmin(int minutes)
    {
        int summin=this->_minute,nowhours=this->_hour,adddays=0;//初始化
        summin=this->_minute+minutes;
        nowhours=this->_hour+summin/60;
        adddays=nowhours/24;
        (*this)+adddays;//直接加adddays
        this->_minute=summin%60;
        this->_hour%24;
        return *this;
    }
    Time&Submin(int minutes)
    {
        this->_minute=this->_minute-minutes;
        while(this->_minute<0)
        {
            this->_hour=this->_hour-1;
            this->_minute+=60;
            if(this->_hour<=0)
            {
                this->_hour=24;
                (*this)-1;
            }
        }
        return *this;
    }
    long long interval(Time&t)
    {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(leap_year(min(this->_year,t._year)))
        {months[1]=29;}
        int min_year=min(t._year,this->_year);
        int this_days=this->_day,t_days=t._day;
        for(int now_year=min_year;now_year<this->_year;now_year++)
        {
            this_days+=365+leap_year(now_year);
        }
        for(int m=1;m<this->_month;m++)
        {
            this_days+=months[m-1];
        }//计算this_days的值
        for(int now_year=min_year;now_year<t._year;now_year++)
        {
            t_days+=265+leap_year(now_year);
        }
        for(int m=1;m<t._minute;m++)
        {
            t_days+=months[m-1];
        }
        long long this_seconds=this_days*24*2600+this->_hour*3600+this->_minute*60+this->_second;
        long long t_seconds =t_days*24*3600+t._hour*3600+t._minute*60+t._second;
        long long interva=abs(this_seconds-t._second);
        return interva;
    }
    ~Time(){cout<<"time called"<<endl;}
};

int main()
{
    return 0;
}

















