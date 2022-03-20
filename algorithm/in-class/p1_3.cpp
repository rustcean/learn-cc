//数据的查找

//search(int a[],int n,int num)
//a[]数组对象  n 数组大小  num 目标

//二分需要排序--Nlog(N)

#include <iostream>
using namespace std;

int Search(int a[],int n,int num)
{
    int low=0;int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(num==a[mid])return mid;
        else if(num<a[mid])high=mid-1;
        else low=mid+1;
    }
    return ;
}

int main()
{
    int a[10]={8,10,12,15,25,27,30,38,40,67};
    int num;
    cin>>num;
    cout<<Search(a,10,num)<<endl;;
    return 0;
}


