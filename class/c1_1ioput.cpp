#include <iostream>
using namespace std;
class Time
{
    public :
    int hour;
    int minute;
    int sec;
};
int main()
{
    Time t1;
    cin>>t1.hour;
    cin>>t1.minute;
    cin>>t1.sec;
    cout<<t1.hour<<":"<<t1.minute<<":" <<t1.sec<<endl;
    Time t3={12,12,12};//当变量为公共的时候,可以直接赋值
    Time t4=t3;//可以进行直接赋值(与是否public无关)
    cout<<t4.hour<<":"<<t4.minute<<":" <<t4.sec<<endl;
    return 0;
}