#include <iostream>
#define SIZE 5//确定数组大小
using namespace std;

int opout(int *p);
int count(int num);

int main()
{
    int shu[SIZE]={1,2,3,4,5};
    opout(shu);
    int n;  
    cout<<"请输入阶梯数：";
    cin>>n;
    cout<<"登上 "<<n<<" 个阶梯共 "<<count(n)<<" 个方法"<<endl;
    return 0;
}


int opout(int *p)//反向输出
{
    static int j=SIZE;
    if(j--!=0) {opout(p+=1);cout<<*(p-1)<<endl;}
    return 0;
}
//跳两格一种跳一格一种
int count(int num)//实现跳1或2阶的递归
{
    if(num==1)
    return 1;
    else if(num==2)
    return 2;
    else 
    return count(num-1)+count(num-2);
}
