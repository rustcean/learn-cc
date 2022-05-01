//快排的实现
#include <iostream>
using namespace std;
const int MAX=10 ;

int Quickpass(int *arr,int low,int high)
{
    int down=low;
    int up=high;
    while(down<up)//不能等于
    {
        while((down<up)&&arr[up]>arr[down])
        {up--;}
        if(down<up)
            arr[down++]=arr[up];//将up位置的值赋给down的位置
        while((down<up)&&arr[down]<arr[up])
            down++;
        if(down<up)
            arr[up--]=arr[down];
        
    }
}
int main()
{
    int arr[MAX];
    
}











