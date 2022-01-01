#include <iostream>
using namespace std;
template <typename T>
T max(T a,T b)
{return a>b?a:b;}
int main()
{
    cout<<"Max(3,5) is "<<((int)max(3,5))<<endl;
    cout<<"max('y','e') is "<<max('y','e')<<endl;
    cout<<"max(9.3,0.5) is "<<max(9.3,0.5)<<endl;
    return 0;
}