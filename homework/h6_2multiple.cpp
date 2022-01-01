#include <iostream>
using namespace std;//找出两个数的最小公倍数
int main()
{
    int n1,n2,max;
    cout<<"输入两个数:";
    cin>>n1>>n2;
    max=n1>n2?n1:n2;
    do
    {
        if(max%n1==0&&max%n2==0)
        {
            cout<<"最小公倍数:"<<max<<endl;
            break;
        }
        else
        ++max;
    }while(true);
    return 0;
    // int m=n1>n2?n1:n2;//least commont mul
    // while(1)
    // {
    //     if(m%n1==0&&m%n2==0)
    //     {
    //         return m;
    //     }
    //     else ++m;
    // }
    
}