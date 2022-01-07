#include <iostream>
#include <ctime>
using namespace std;
class Date
{
    int day;
    int month;
    int year;
    public:
    int isleapyear(int year)
    {
    if((year%4==0&&year%100!=0)||(year%400==0))
    return 1;
    return 0;
    }
    int getdays(Date &d)
    {
    int m[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(year))
    m[2]++;
    int result=0;
    for(int i=0;i<d.year;i++)
    {
        result+=365;
        if(isleapyear(i))
        result++;
    }
    for(int i=1;i<d.month;i++)
    {
        result+=m[i];
    }
    result+=d.day;
    return result;
    }
};

/*之前写的错误内容,想通过直接从一个日期到另一个日期来解,但是失败了
if((d1.day==d2.year&&d1.month==d2.month)&&(d1.day==d2.day))
    return 0;
    else if(d1.year>d2.year)
    {
        int days=0;
        int chazhi_year=d2.year ;
        int chazhi_month=d2.month+1;
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        while (chazhi_year<d1.year)
        {
            while(chazhi_month<=12)
            {
                days+=months[chazhi_month-1];
                chazhi_month++;
            }
            chazhi_year++;
            chazhi_month=0;
        }

*/