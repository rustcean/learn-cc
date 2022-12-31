//递归做法
#include <iostream>
using namespace std;
int akm(int n,int m)
{
    if(m==0)
    {return n+1;}
    else if(n==0)
    {
        return akm(m-1,1);
    }
    else  return akm(m-1,akm(m,n-1));
}

int main()
{
    int a=1,b=2;
    int c=akm(a,b);
    cout<<"结果为: "<<c<<endl;
}

