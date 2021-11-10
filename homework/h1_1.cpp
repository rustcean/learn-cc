#include <iostream>
using namespace std;
int main()
{
    int a[20];
    int i=0,max=0;
    do
    {
        cin>>a[i];
        i++;
    } while (a[i-1]!=0);
    for(int j=0;j<i;j++)
    {
        max=max>a[j]?max:a[j];
    }
    cout<<max<<endl;
}