#include <iostream>
using namespace std;
int main()
{
    int max(int x,int y);
    int (*p)(int,int);
    p=max;
    int a,b,m;
    cin>>a>>b;
    m=p(a,b);
    cout<<"max= "<<m<<endl;
    return 0;
}
int max(int a,int b)
{return a>b?a:b;}