#include <iostream>

using namespace std;
int main()
{
    
    char  a[50]=" good ";
    cout<<"array:"<<a<<endl;//输出了值
    int b[2]={1,2};
    cout<<b<<endl;//输出了地址
    string c[2]={"asss","aaa"};
    cout<<c<<endl;//输出了地址
    char x[2]={'a','b'};
    cout<<x<<endl;//数组溢出了,输出了"good"离谱
    cout<<&x<<endl;//输出了地址
    return 0;

}