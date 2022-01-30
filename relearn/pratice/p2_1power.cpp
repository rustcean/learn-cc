/*x的n次幂求*/
#include <iostream>
using namespace std;
/*求幂次函数*/
double power(double x,int n);

int main()
{
    int x;
    cout<<"输入x"<<endl;
    cin>>x;
    int wei=0;
    int sum =0;
    int each,chu;
    for(int i=0;i<8;i++)
    {
        each=x%10;//取余
        chu=x/10;//
        sum+=each*power(2,wei);//2^
        x=chu;//降一位的值重新赋值给x
        wei++;//位数加1
    }
    cout<<sum<<endl;
    return 0;
}

double power(double x,int n)
{
    double va1=1.0;
    while(n--)
    {
        va1*=x;
    }
    return va1;//返回x的n次幂
}

/*
输入1234时:
each  4        each:2^0
      3             2^1
      2             2^2
      1             2^3
输出: 4*2^0+.....=26
*/