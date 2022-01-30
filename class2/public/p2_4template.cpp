#include <iostream>
using namespace std;

template <class T>
class Array
{
    T a[100];
    int l;
    public:
    Array(T *x,int y);
    void reverse();
    void print();
    void sort();
    void find(T t);
    void sum();
};
template <class T>
Array<T>::Array(T *x,int y)
{
    l=y;
    for(int i=0;i<l;i++)
    a[i]=x[i];
}

template <class T>
void Array<T>::reverse()
{
    int i;
    T d[l];
    for(i=0;i<l;i++)
    d[i]=a[l-1-i];
    for(i=0;i<l;i++)
    a[i]=d[i];
}
template <class T>
void Array<T>::print()
{
    cout<<"the array elements are:"<<endl;
    for(int i=0;i<l;i++)
    {
        cout<<a[i]<<" ";
        
        if((i!=0)&&(i%8==0))
        {cout<<endl;}
    }
    cout<<endl;
}

template <class T>
 void Array<T>::sort()
{
    T temp;
    for(int i=0;i<l;i++)
    {
        for(int j=i;j<l;j++)
        if(a[i]>a[j])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
}

template <class T>
void Array<T>::find(T t)
{
    int flag=0;
    for(int i=0;i<l;i++)
    {
        if(a[i]==t)
        {flag=1;
        cout<<"是第"<<i+1<<"个元素"<<endl;
        break;
        }
    }
    if(flag==0)
    {cout<<"未找到该元素"<<endl;}
}
template <class T>
void Array<T>::sum()
{
    int i=0;
    T sum=0;
    for(i=0;i<l;i++)
      sum+=a[i];
    cout<<"数组和为:"<<sum<<endl;
}

int main()
{
    int i,x,y;
    int q;//用来查找元素
    double p;//用来查找元素
    cout<<"请输入两种数组元素个数:"<<endl;
    cin>>x>>y;//x是inty是double
    int *a;
    double *b;
    a=new int [x];//分配x个 int内存
    b=new double [y];// 分配y个double内存
    cout<<"请输入int型数组元素:"<<endl;
    for(i=0;i<x;i++)
       cin>>a[i];
    cout<<"请输入 doule型数组元素:"<<endl;
    for(i=0;i<y;i++)
       cin>>b[i];
    Array<int> c(a,x);
    Array<double> d(b,y);
    cout<<"int数组:"<<endl;
    c.print();
    cout<<"排序后"<<endl;
    c.sort();
    c.print();
    cout<<"倒序后:"<<endl;
    c.reverse();
    c.print();
    c.sum();
    cout<<"请输入要查找的元素:";
    cin>>q;
    c.find(q);
    cout<<"double数组:"<<endl;
    d.print();
    cout<<"排序后"<<endl;
    d.sort();
    d.print();
    cout<<"倒序后:"<<endl;
    d.reverse();
    d.print();
    d.sum();
    return 0;  

}