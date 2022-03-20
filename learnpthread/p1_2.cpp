#include <iostream>
using namespace std;
int main()
{
    char a='9';//不能有两个字符
    int b=a -'0';//相当于输出他们的ASCII值的差值
    cout<<b<<endl;
    int c=(char)a;//得到他的ASCII绝对值
    cout<<c<<endl;
    char d=(char)c;//输出9
    cout<<d<<endl;
    cout<<wctype("printf")<<endl;
}