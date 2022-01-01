//本date类没有判断润年情况,以及输入的日期是否合理的问题
//现在已经与c1_4**.cpp一起编译了,若想用得重新编译
#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;
    public:
    Date();
    Date(int y=1900,int m=1,int d=1 );
    int get_year();                 //year获取
    int get_month();                //month获取
    int get_day();                  //day获取
    void getin_year();              //year外部输入
    void getin_month();             //month外部输入
    void getin_day();               //day外部输入
    void set_year(int y);           //year内部设置
    void set_month(int m);          //month内部设置
    void set_day(int d);            //day内部设置
};
//函数实现
Date::Date()
{
    year=1900;
    month=1;
    day=1;
}
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
int Date::get_year(){return year;}
int Date::get_month(){return month;}
int Date::get_day(){return day;}
void Date::getin_year()
{
    cout<<"please input year:";
    cin>>year;
}
void Date::getin_month()
{
    cout<<"please input month:";
    cin>>month;
}
void Date::getin_day()
{
    cout<<"please input day:";
    cin>>day;
}
void Date::set_year(int y){year=y;}
void Date::set_month(int m){month=m;}
void Date::set_day(int d){day=d;}

//以下为测试
/*
int main()
{
    Date d1(2021,12,23);
    Date d2;
    cout<<d2.get_year()<<":"<<d2.get_month()<<":"<<d2.get_day()<<endl;
    cout<<d1.get_year()<<":"<<d1.get_month()<<":"<<d1.get_day()<<endl;
    d2.getin_year();
    d2.getin_month();
    d2.getin_day();
    d1.set_year(2022);
    d1.set_month(12);
    d1.set_day(12);
    cout<<d1.get_year()<<":"<<d1.get_month()<<":"<<d1.get_day()<<endl;
    cout<<d2.get_year()<<":"<<d2.get_month()<<":"<<d2.get_day()<<endl;
}
*/