//雨水问题--华师天梯2022选拔--40/50
#include <iostream>
using namespace std;
int main()
{   
    unsigned int n;
    scanf("%d",&n);
    unsigned int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int c=0;//记录次数
    int length=0;
    int left=arr[0];
    for(int i=1;i<n;i++)
    {
        int min=0x3f3f3f;
        if(left<=arr[i])
        {
            left=arr[i];
            continue;
        }
        else if(left>arr[i])
        {
            int right=arr[i];
            int j=i;
            int x=0;
            for(;j<n;j++)
            {
                if(right<arr[j])
                {
                    if(right>=left)break;
                    right=arr[j];
                    x=j;
                }
            }
            if(x>i)
            {
                for(int k=i;k<x;k++)
                {
                    if(min>arr[k])
                    min=arr[k];
                }
                int wall=left<right?left:right;
                int len=wall-min;
                length=length>len?length:len;
                left=right;
                c++;
                i=x;
            }
            else if(x==i)
            {
                i=x;
                left=right;
                continue;
            }

        }       
    }
    printf("%d\n",c);
    printf("%d\n",length);
    return 0;

}
