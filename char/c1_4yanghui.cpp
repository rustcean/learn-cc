#include <iostream>
#include <iomanip>
using namespace std;
int yanghui(int num)
{
    int  a[num][num];
    for(int i=0;i<num;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(int i=1;i<num;i++)//从第二行开始
    for(int j=1;j<i;j++)//
    a[i][j]=a[i-1][j-1]+a[i-1][j];
    
    for(int i=0;i<num;i++)
    {
    for(int j=0;j<i+1;j++)
    cout<<a[i][j]<<" ";
    
    cout<<endl;
    }
return 0;
}
int main()
{
    int n;
    cout<<"please input the num:";
    cin>>n;
    yanghui(n);
    return 0;   
}

// int n;//不用作为全局变量也可以
// int main()
// {
//     cin>>n;
//     int a[n][n];//
//     for(int i=0;i<n;i++)
//     {
//         a[i][0]=1;//每一行的第一个数定为1
//         a[i][i]=1;//每一行的最后一个数定为1
//     }
//     for(int i=1;i<n;i++)
//     for(int j=1;j<i;j++)
//     a[i][j]=a[i-1][j-1]+a[i-1][j];//每一行的一个数由上一行的两个数的和
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<i+1;j++)
//         //cout<<setw(2)<<a[i][j];虽然对齐但是太丑了
//         cout<<a[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }