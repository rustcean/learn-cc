/*
逆序对 --概念:
设 A 为一个有n个数字的有序集(n>1)，其中所有数字各不相同。
如果存在正整数i,j，使得1≤i<j≤n 
并且 A[i]>A[j]，则 ⟨A[i],A[j]⟩ 这个 有序对 称为 A 的一个 逆序对，也称作逆序数。
(简单来说，就是如果i比j小，但是 A[i]比A[j]大，那么<A[i],A[j]>就是一个逆序对)
排序的过程就是消除逆序对的过程。逆序对越多，相对来说排序所需要的时间就越多。

借助归并排序:
一个升序数组，逆序对为0。数组中一个连续段之间的逆序对交换，只会影响段内的逆序对数，
而不会影响段外的逆序对，段外的元素与段内的元素之间的逆序对数也不受影响

下面的临时数组是全局变量，是为了方便。如果想要把整个计算过程封装到函数内，可以参考递归归并排序的避免频繁开辟内存写法
*/ 

#include <iostream>
using namespace std;

#define length 10
//定义数组
int a[length], temp[length];
//合并有序数列，同时计算逆序对
int merge(int a[],int left,int mid,int right)
{
    int count=0;
    //先归并到临时数组中
    int i=left,j=mid+1;
    for(int k=left;k<=right;k++)
    {
        if((j>right)||(i<=mid) && (a[i]<=a[j]))
            temp[k]=a[i++];
        else{
            temp[k]=a[j++];
            count+=mid-i+1;      //计算逆序对数
        }
    }

    //复制回数组a
    for(int i=left;i<=right;i++)
        a[i]=temp[i];
    
    return count;
}

//归并
int Count(int a[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        //
        return Count(a,left,mid)
        +Count(a,mid+1,right)
        +merge(a,left,mid,right);
    }
    else return 0;
}
//主函数
int main()
{
    for(int i=0;i<length;i++)
        a[i]=length-i-1;
    cout<<"未排序前:"<<endl;
    for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    int num=Count(a,0,length-1);
    
    cout<<"排序后:"<<endl;
    for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
    cout<<endl<<endl;

    cout<<"逆序对数为"<<num<<endl;
}


/*
时间复杂度 O(nlogn)
*/




