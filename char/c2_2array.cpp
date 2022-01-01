#include <iostream>
using namespace std;
int main()
{
    char str1[]="I love China!",str2[20],*p1,*p2;
    p1=str1;
    p2=str2;
    for(;*p1!='\0';p1++,p2++)
    {
        *p2=*p1;
    }
    *p2='\0';//此时的p2已经指向了str2的没有意义字段,所以用来结尾
    p1=str1;
    p2=str2;
    cout<<"str1 is "<<p1<<endl;//有点东西
    cout<<"str2 is "<<p2<<endl;//
    return 0;
}