#include <iostream>
using namespace std;

int Search(int a[],int n,int num)
{
    int i;
    int Min=0x3f3f3f3f;
    //int Min=a[0];--//后面可以从a[1]开始

    for(i=0;i<n;i++)
    {
        if(Min>a[i])Min=a[i];
    }
}
int main()
{

}
//1067