#include <iostream>
using namespace  std;
int main()
{
    // if(0)
    // cout <<"a"<<endl;
    cout<<"input a year"<<endl;
    int year;
    cin>>year;
    if(year%4==0&&year%100!=0||year%400==0)
    {cout<<"it is a leap year"<<endl;}
    else
    cout<<"it isn' t a leap year"<<endl;
    return 0;
} // namespace  std;
