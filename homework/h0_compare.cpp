#include <iostream>    
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
    string str1="大家好";
    string str2="大家好";
    cout<<str1<<endl;
    cout<<str2<<endl;
    if(str1.compare(str2)>0)//compare函数用来比较
    cout<<"大于"<<endl;
    else if(str1.compare(str2)<0)
    cout<<"小于"<<endl;
    else cout<<"等于"<<endl;
    if(str1.compare(1,2,str2)==0)
    cout<<"等于"<<endl;
    if(str1.compare(1,2,"大家好",2)==0)
    cout<<"等于"<<endl;
    else cout<<"不等于"<<endl;


    char str3[5]="a";//  char数组得用""
    cout<<strlen(str3)<<endl;

    char str4[20]="我";
    cout<<strlen(str4)<<endl;

    char str[50];//定义数组
    int leng;
    strcpy(str,"This is runoob,com");//将数组赋值
    leng=strlen(str);
    cout<<leng<<endl;

    
    return 0;
}