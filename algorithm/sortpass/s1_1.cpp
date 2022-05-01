//直接插入排序
#include <iostream>
using namespace std;
int main()
{
  int a[]={98,23,37,45,239,23,349,0,12};
  int k=sizeof(a)/sizeof(a[0]);
  int i,j;
  for(i=1;i<k;i++)//循环从第二个元素开始
  {
    if(a[i]<a[i-1])
    {
        int temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)//j=0之后还会减1
        {
            a[j+1]=a[j];//从i开始,将大于temp的值往数组后面移动
        }
        a[j+1]=temp;//此处就是a[j+1]
    }   
  }
  for(int f=0;f<k;f++)
  {
        cout<<a[f]<<" ";
  }
  cout<<endl;
  return 0;
}

//现在尝试写成一个函数
void pass(int *arr,int length)
{
    int i,j;
    for(i=1;i<length;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int temp=arr[i];
            for(j=i-1;j>0&&arr[j]>temp;j--)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;
        }
    }
}
