//天梯选拔-5题
#include <iostream>
using namespace std;
struct data
{
    int a;
    int b;
    int c;    
};
int main()
{   
    double re=0.0;
    int n,m;
    scanf("%d %d",&n,&m);
    struct data arr[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
    }
    int first=1;
    if(first==arr[0].a)
    {   
        first=arr[0].b;
        re+=arr[0].c;    
    }
    printf("%.3f\n",re);
}
