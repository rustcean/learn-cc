#include <iostream>
using namespace std;

int main()
{
    int a,b,c;

    while(1)
    {
        cin>>a>>b>>c;
        if(a || (b && c))  //没加()一样
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}