//shell排序--分多路的插入排序--此处是分三段
#include <iostream>
using namespace std;
template <typename T>
void shell_sort(T array[], int length)
{
    int h=1;
    while (h<length/3)
    {
        h=3*h+1;
    }
    while(h>=1)
    {
        for(int i=h;i<length;i++)
        {
            for(int j=i;j>=h && array[j]<array[j-h];j-=h)
                std::swap(array[j],array[j-h]);
            //h=1时,就是冒泡...不好
        }
        h=h/3;
    }
}


int main()
{
    int arr[5]={5,4,3,2,1};
    shell_sort(arr,5);
    for(int i=0;i<5;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
