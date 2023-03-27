// 最大子数组-动态规划 O(n)

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void maxSubArray(int* a, int length){
    int n=length;           //数组长度
    int maxint=INT8_MIN;    //记录最大值
    int sum=0;              //记录每一次和   
    int last;               //记录子数组尾巴
    stack <int> num;        //记录子数组内容
    sum=a[0];
    for(int i=1;i<n;i++)
    {
        sum=max(a[i]+sum,a[i]);  
        /*像是滑动窗口一样 不断向后滑的时候，如果一直变大，那么
        就是就是该数在子数组中，如果变小就是子数组没有该数更好
        所以就断了，继续找，找到新的最大值就是说该子数组更大
        */
        if(sum>maxint){
            maxint=sum;
            last=i;
        }
    }
    cout<<"最大值为: "<<maxint<<endl;
    while(maxint!=0){
        maxint-=a[last];
        num.push(a[last]);
        last--;
    }
    cout<<"内容为: ";
    while(!num.empty())
    {
        cout<<num.top()<<" ";
        num.pop();
    }
    cout<<endl;
}

int main()
{
    cout<<"输入数组长度和内容: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    maxSubArray(arr,n);
    return 0;
}
