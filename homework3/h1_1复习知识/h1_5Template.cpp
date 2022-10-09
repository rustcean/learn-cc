/*
编写一个使用类模板对数组进行元素循环右移操作的程序
M N
x x x x   --M个
循环问题:取余 

*/

#include <iostream>
using namespace std;

const int N=100;

template <class T>
class Array
{
    T arr[N];
    int length;
    public:
    Array(T *x,int m);
    void R_move(int n);
};


template <class T>
Array<T>::Array(T *x,int m)
{
    length=m;
    for(int i=0;i<length;i++)
    arr[i]=x[i];
    // //测试
    // for(int i=0;i<m;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
}

template <class T>
void Array<T>::R_move(int n)
{
    int num=n%length;
    int i,j;
    for( i=0;i<length;i++)
    {
        j=i+num;
        if(j>=length)
            j=j%length;
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int array[N];
    for(int i=0;i<m;i++)
        cin>>array[i];
    Array<int> Arr(array,m);
    Arr.R_move(n);
    return 0;
}
/*
6 8 
1 2 3 4 5 6

*/

