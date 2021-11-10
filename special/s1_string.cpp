#include <iostream>
using namespace std;
int main()
{
    string a,b,c;
    cin>>a;  //不能有空格，会读成两个变量的内容
    cin>>b;
    c=a+b;
    cout<<c<<endl;
    a="very good ";//like a 数组
    b="student !";
    c=a+b;
    cout<<c<<endl;
    return 0;
}
