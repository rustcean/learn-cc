//选择排序
#include <iostream>
using namespace std;
//函数实现
//解释:每次都从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
template <typename T>
void selection_sort(T *arr, int length)
{
    for(int i=0;i<length-1;i++)
    {
        int min=i;
        for(int j=i+1;j<length;j++)
            if(arr[j]<arr[min])
                min=j;
        std::swap(arr[i],arr[min]); //交换
    }
}
int main()
{
    //定义数组
    int length=10;
    int arr[length]={9,8,7,6,5,4,3,2,1,0};
    //交换前
    cout<<"交换前:"<<endl;
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    //执行排序函数
    selection_sort(arr,length);
    //交换后
    cout<<"交换后:"<<endl;
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
/*
分析:由于每次都是从剩余剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾，即每次都是遍历一边
故，时间复杂度为O(n平方)
*/
