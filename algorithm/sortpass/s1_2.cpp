// //二分法插入排序
// #include <iostream>
// using namespace std;
// void TwoInsertSort(int *arr,int n)
// {
//     int left,right,num;
//     int middle,j,i;
//     for(i=1;i<n;i++)//不是从0开始
//     {
//         left=0;//每次left都会从0开始
//         right=i-1;
//         num=arr[i];
//         while(right>=left)//二分查找插入位置
//         {
//             middle=(left+right)/2;//指向已排序好法中间位置
//             if(num<arr[middle])//即将插入的元素应当在左区间
//             right = middle -1;
//             else
//             left=middle+1;
//         }
//         //每次查找完毕偶,left总比right大1,a[left]总是存放第一个比num的的数
//         //因此应从此处开始,每一个元素右移一位,保证是排好序的
//         for(j=i-1;j>=left;j--)
//             arr[j+1]=arr[j];
//         arr[left]=num;//插入
//     }
// }


//从大排到小
// #include <iostream>
// using namespace std;
// void set(int *arr,int n)
// {
//     int left,middle,right,num;
//     int i,j;
//     for(int i=1;i<n;i++)
//     {
//         left=0;
//         right=i-1;
//         num=arr[i];//暂存arr[i]的值
//         while(left<=right)
//         {
//             middle=(left+right)/2;//将放在中间用来与arr[i]比较
//             if(num>arr[middle])
//             {
//                 right=middle-1;
//             }
//             else
//             {
//                 left=middle+1;
//             }
//         }//注意,最终left指到的位置,就是要用来交换数据的位置
//         cout<<left<<" "<<middle<<endl;
//         for(j=i-1;j>=left;j--)//没写等于号出错了,
//         {
//             arr[j+1]=arr[j];//将比arr[i]小的数往后移动,
//         }
//         arr[left]=num;//插入
//     }
// }


//试一试用right实现--需要从右边开始
#include <iostream>
using namespace std;
void set(int *arr,int n)
{
    int left,middle,right;
    int i,j,num;
    for(i=n;i>=0;i--)//left会直接从0开始,所以不需要从0开始
    {
        right=n;//num会记录arr[i]的值,不需要从i开始
        left=i+1;
        num=arr[i];
        while(left<=right)
        {
            middle=(left+right)/2;
            if(arr[middle]>num)
                right=middle-1;
            else
                left=middle+1;
        }
        for(j=i+1;j<=right;j++)
        {
            arr[j-1]=arr[j];
        }
        arr[right]=num;
    }
}

int main()
{
    int array[9]={1,10,12324,3,0,23,56,71,4};
    set(array,9);
    for(int i=0;i<9;i++)//数组越界竟然没报错
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//没有预料到的意外,数组越界了竟然没有报错,导致结果出错
//在使用函数的时候,竟然就已经出错了(输入的数字越界了),但没有报错
//没有料想到第三个版本也出现了数组越界的情况,但程序运行很奇怪
//修改逆序时候,不能只修改  ">" 