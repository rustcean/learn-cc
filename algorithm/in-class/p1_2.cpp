//优化
#include <iostream>
using namespace std;
int main()
{
    int n,r,i=0,j,m;
    cin>>m;
    while(m--)
    {
        cin>>n;
        i=0;
        while(n)
        {
            r=n%2;
            n=n/2;
            if(r==1)
            {
                cout<<i;
                if(n!=0)cout<<" ";
            }
            i++;
        }
        cout<<endl;
    }
}


