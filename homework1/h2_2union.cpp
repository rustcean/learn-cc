#include <iostream>
using namespace std;
union data
{
    int i;
    char ch;

}a,b,c;
int main()
{
    a.i=1;
    b.i=3;
    c.i=2;
    cout<<a.i<<b.i<<c.i<<endl;
    return 0;
}