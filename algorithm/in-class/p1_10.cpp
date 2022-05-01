//数组实现,转圈数数
#include <iostream>
using namespace std;
void Josephus(int n,int start,int m )//m--步数
{
    int counter,j,*arr=new int [n];
    for(j=0;j<n;j++)
    {arr[j]=j+1;}

    counter=1;//这里先置一了,所以while里面是先求余再++
    start--;
    while(counter<n)
    {
        cout<<arr[start]<<" ";//输出当前
        for(j=start;j<n-counter;j++)
            arr[j]=arr[j+1];//将start后的数据向前移动一位
        start=(start+m-1)%(n-counter);
        counter++;//
    }
    cout<<arr[0];
    delete arr;//程序结束的时候,内存是会自动释放的,所以似乎也不用delete
}

int main()
{
    Josephus(10,3,2);
    cout<<endl;
    return 0;
}


