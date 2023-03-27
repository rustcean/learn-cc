//插入排序 计算逆序对

#include <iostream>
using namespace std;

//插入排序算法--每一次交换就是一对逆序对
template <typename T>
int count_insert_sort(T a[],int length)
{
    int count=0;
    for(int i=1;i<length;i++)
    {
        T key=a[i];
        int j;
        for(j=i-1;j>=0 && a[j]>key;j--)
        {
            a[j+1]=a[j];
            count++;
        }
        a[j+1]=key;
    }
    return count;
}
//主函数
int main()
{
    int length =10;
    int arr[length];
    for(int i=0;i<length;i++)
        arr[i]=length-i-1;
    cout<<"排序前:"<<endl;
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int num=count_insert_sort(arr,length);
    cout<<"排序后:"<<endl;
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;
    cout<<"逆序对数: "<<num<<endl;
    return 0;
}