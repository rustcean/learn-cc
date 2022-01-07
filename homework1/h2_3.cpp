#include <iostream>
#include <iomanip>
#define NUM 9
using namespace std;
int sort(int *p,int num)//
{
    int i,j;
    for(i=0;i<num;i++)
    for(j=0;j<num-i;j++)
    if(*(p+j+i)<*(p+i))
    {
        int temp=*(p+j+i);
        *(p+j+i)=*(p+i);
        *(p+i)=temp;
    }
    return 0;
}
int input(int *p,int num)//
{
    for(int i=0;i<num;i++)
    cin>>*(p+i);
    return 0;
}
int out(int *p,int num)
{
    for(int i=0;i<num;i++)
    cout<<*(p+i)<<setw(2);
    cout<<endl<<*(p+(num/2))<<endl;
    cout<<p+num/2<<endl;
    return 0;
}
int main()
{
    int a[NUM];
    cout<<"input "<<NUM<<" numbers :";
    input(a,NUM);
    sort(a,NUM);
    out(a,NUM);
    return 0;
}