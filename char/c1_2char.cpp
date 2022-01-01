#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[20]="abcd";
    cout<<a[20]<<endl;//读了不知道什么的东西,一位
    cout<<*a<<endl;//输出了第一个字符
    char d[]="abcd";//用单引号直接报错--单引号是当成了int型
    cout<<*(d+1)<<endl;
    int i=0;
    while(d[i]!=0)//帅哦,可以有!!
    {
        cout<<d[i]<<" ";
        i++;
    }
    
    char const *f="abc";
    char* g=(char*)"abcd";//类型转换
    cout<<endl<<*f<<" "<<*g<<endl;
    int h=(int)'a';//类型转换
    cout<<h<<endl;
    //"abc"是一个不变常量在c++中叫做string literaltype是const char* 

    // char *c;//Segmentation fault (core dumped)
    // cin>>c;
    // cout<<*c<<endl;


    // char e[5]={'a','b','c','d','e'};
    // cout<<e[5]<<endl;//输出a
    // cout<<e<<endl;//输出a
    // for(int i=0;i<5;i++)
    // cout<<*(e+i);    


    // char b[20];
    // cin>>*b;//只读了一个字母
    // cout<<*b<<endl;
    
    return 0;
}