#include <iostream>  //add 0 to M
using namespace std;
int main()
{
    int i=0,M,sum=0;
    cout<<"input a number ,we will add 0 to it :";
    cin>>M;
    while(i<=M)
    {
        sum=sum+i;
        i++;
    }
    cout<<"result is "<<sum<<endl;
    return 0;
}