//隐式调用template函数
//重点,排序的方法:
#include <iostream>
using namespace std;
template <class T>
void sort(T *a,int n)///
{
    for(int i=0;i<n;i++)//冒泡排序--先找到最大值,再交换--更好
    {
        int p=i;
        for(int j=i;j<n;j++)
          if(a[p]<a[j])
            p=j;
        T t=a[i];
        a[i]=a[p];
        a[p]=t;
    }
}

// void sort(T*a,int n)//冒泡排序--一个一个交换,直到最大值
// {
//     T temp;
//     for(int i=0;i<n;i++)
//      for(int j=i;j<n;j++)
//       if(a[i]<a[j])
//       {
//           temp=a[j];
//           a[j]=a[i];
//           a[i]=temp;
//       }
// }


template <class T>
void display(T &a,int n)
{
    for(int i=0;i<n;i++)
    
    {
        cout<<a[i]<<"\t";
        if(i!=0&&i%5==0)
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int a[]={1,41,2,5,8,21,23};
    char b[]={'a','x','y','e','q','g','o','u'};
    sort(a,7);
    sort(b,8);
    display(a,7);
    display(b,8);
    return 0;
}