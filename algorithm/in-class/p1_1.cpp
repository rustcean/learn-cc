#include <iostream>
using namespace std;
int main()
{
    int n,s[100],i=0;
    //s[10]太小
    cin>>n;
    while(n)
    {
        s[i++]=n%2;
        n=n/2;
    }
    int k=0;
    while(--i>=0)
    cout<<s[i];
    cout<<endl;
    return 0;
}


//核心算法需要把变量初始化工作好
//声明与初始化分开


//栈溢出--数组申请太大
//数组满足大小
//分析题目要求的数据规模
//数组尽量安排为全局变量
//memcs
//cs--设置
//输出的格式问题

//AC后,分析内能不能优化代码--时间空间
//功能合并--同种循环可否合并

