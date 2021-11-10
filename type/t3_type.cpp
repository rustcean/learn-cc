#include <iostream>
using namespace std;
int main()
{
    int add(long int x,long int y);
    int a=add(123L,23L);
    cout<<"add L : "<<a<<endl;
    a=add(123,23);
    cout<<"no add "<<a<<endl;
    a=add(020,022);
    cout<<"eight binary 20+22= "<<a<<endl;
    a=add(0X20,0x20);
    cout<<"sixteen binary 20+20= "<<a<<endl;
    cout<<"\\n\n";
}
int add(long int x,long int y)
{
    int sum=x+y;
    return(sum);
}