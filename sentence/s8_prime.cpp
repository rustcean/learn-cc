#include <iostream>
#include <cmath>//用于sqrt的使用
#include <iomanip>//用于setw的使用
using namespace std;
int main()
{
    int m,k,i,n=0;
    bool prime;
    for(m=101;m<=200;m+=2)
    {
        prime=true;
        k=int(sqrt(m));
        for(i=2;i<=k;i++)//进行判断
        {
            if(m%i==0)
            {
                prime=false;
                break;
            }
           
        }
        if(prime)//为素数的输出
        {
            cout<<setw(5)<<m;
            n+=1;
        }
        if(n%10==0)
        cout<<endl;
    }
    cout<<endl;
    return 0;
}