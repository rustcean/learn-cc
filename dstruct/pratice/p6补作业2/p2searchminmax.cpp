#include <iostream>
using namespace std;
//查找函数
void search(int a[],int length)
{
    int max=a[0];
    int min=a[0];
    for(int i=1;i<length;i++)
    {
        if(max<a[i]){max=a[i];}
        else if(min>a[i]){min=a[i];}        
    }
    cout<<"最大值: "<<max<<endl;
    cout<<"最小值: "<<min<<endl;
}

int main()
{
    int a[6]={4,1,6,4,8,3};
    cout<<"数组的内容:"<<endl;
    for(int i=0;i<6;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    search(a,6);
    return 0;
}