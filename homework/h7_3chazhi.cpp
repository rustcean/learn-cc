#include <iostream>
using namespace std;

int leap_year(int now_year)
{
    if((now_year%4==0&&now_year%100!=0)||(now_year%400==0))
    return 1;
    return 0;
}
int main()
{
    int d1month=10,d1day=11,d1year=2020;
    int d2month=5,d2day=13,d2year=2019;    //cin>>d2year>>d2month>>d2day;
    int days=0;
    int chazhi_year=d2year ;
    int chazhi_month=d2month+1;
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    days=months[d2month-1]-d2day;
    while(chazhi_year<d1year)
    {
        if(leap_year(chazhi_year))
        months[1]=29;
        while(chazhi_month<=12)
        {
            days+=months[chazhi_month-1];
            chazhi_month++;
        }
        chazhi_year++;
        chazhi_month=0;
    }
    if(leap_year(d1year))
    months[1]=29;
    for(chazhi_month=0;chazhi_month<d1month;chazhi_month++)
    {
        days+=months[chazhi_month-1];
    }
    days+=d1day;
    cout<<days<<endl;
    
        
}