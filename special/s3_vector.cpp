#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main()
{
    // int a(5);
    // vector <int>b(a);
    // for(int i=0;i<a;i++)
    // {
    //     cin>>b[i];
    // }
    array <char,3> c1={'a','b','s'};
    cout<<c1[1]<<endl;
    //vector <char> a2(&c1,&c1+2);/*vector只能由vector赋值，对象还得相同*/
    return 0;
}