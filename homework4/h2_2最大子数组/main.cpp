// 枚举优化  最大子数组 O(n^2)
//最大子数组: 连续且非空的一段使得这段和最大
#include <iostream>
#include <stack>
using namespace std;

void maxSubArray(int *a,int length){
    int n=length;           //数组长度
    int max=INT8_MIN;       //记录最大值
    int sum;                //记录每一次和   
    stack <int> num;        //记录子数组内容
    //数据处理
    for(int i=0;i<n;i++){   //一个一个遍历
        sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum>max){    
            /*找到更大的子数组时就清空栈，重新记录
            优化:其实可以用shyan.cpp的方法-直接记录位置,
                最后再做栈
            */
                max=sum;
                //清空栈
                while(!num.empty())
                {num.pop();}
                //重做栈
                for(int k=j;k>=i;k--)
                    num.push(a[k]);
            }
        }
    }
    //数据输出
    cout<<"最大子数组的和为: "<<max<<endl;;
    cout<<"对应内容为: ";
    while(!num.empty()){
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