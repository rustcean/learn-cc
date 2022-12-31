#include <iostream>
using namespace std;

void swap(int a[],int length)
{
    for(int i=0;i<length/2;i++)
    {
        int tmp=a[i];
        a[i]=a[length-i-1];
        a[length-i-1]=tmp;
    }
}int main()
{
    int a[4]={1,2,3,4};
    cout<<"交换前:"<<endl;
    for(int i=0;i<4;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    swap(a,4);
    cout<<"交换后:"<<endl;
    for(int i=0;i<4;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}