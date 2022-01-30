//枚举常量
#include <iostream>
using namespace std;
enum weekday{s,m,t,w,thu,f,s1};

int main()
{
    cout<<s<<endl;
    cout<<m<<endl;
    weekday wek =s;
    for(int i=wek;i!=f;i++)
    {
        cout<<i<<endl;
        cout<<wek+s<<endl;
        cout<<"........||.........."<<endl;
    }
    return 0;
}