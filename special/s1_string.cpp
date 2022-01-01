#include <iostream>
using namespace std;
int main()
{
    string a,b,c;
    cin>>a;  //不能有空格，会读成两个变量的内容
    cin>>b;
    c=a+b;
    cout<<c<<endl;//输入 12 12 输出1212
    a="very good ";//like a 数组
    b="student !";
    c=a+b;
    cout<<c<<endl;
    

    cout<<"输入句子"<<endl;
    cin.get();
    getline(cin,a);
    cout<<a<<endl;
    return 0;
}
