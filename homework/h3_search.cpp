#include <iostream>
#define NUM 5
using namespace std;
void input(int *p)
{
    int i;
    for(i=0;i<NUM;i++)
    {
        cin>>*(p+i);
    }
    for(i=0;i<NUM;i++)//冒泡法换位
    for(int j=i+1;j<NUM;j++)//j+1是因为跟i下一个开始比较
    if(*(p+j)>=*(p+i))
    {
       int t;
       t=*(p+j);
       *(p+j)=*(p+i);
       *(p+i)=t;
    }
}
int output(int *p)
{
    for(int i=0;i<NUM;i++)
    cout<<*(p+i)<<endl;
    return 0;
}
int search(int a,int *p)
{
    int x=0;
    for(int i=0;i<NUM;i++)
    if(a==*(p+i))
    {cout<<"y is num "<<i+1<<endl;x=1;}
    if(x==0)cout<<"sorry no number is in "<<endl;
    return 0;
}
int main()
{
    int a[NUM];
    char x;//判断是否search number
    cout<<"please input "<<NUM<<" numbers"<<endl;
    input(a);//输入并排序
    output(a);//输出
    cout<<"do you want to search a number?:y/n ";
    cin>>x;
    if(x=='y')
    {
        cout<<"please input the number:";
        int b;//用来寻找的数
        cin>>b;
        search(b,a);
    }
    else if(x=='n') 
    {
        cout<<"ok,have a good live"<<endl;
        return 0;
    }
    else cout<<"error"<<endl;
    return 0;
}