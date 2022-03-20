/*注意:当设置的变化之后,后面的会默认前面的设置

*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char c[30]="this is a string";
    double d=-1234.12;
    cout<<left<<setw(30)<<setfill('*')<<d<<"---L1"<<endl;
    cout<<setw(30)<<right<<setfill('*')<<c<<"---L2"<<endl;
    //showbase显示数值的基数前缀
    cout<<dec<<showbase<<showpoint<<setw(30)<<d<<"----L3"<<endl;
    cout<<right<<setfill('&')<<setw(30)<<d<<"----L3"<<endl;
    //showpoint显示小数点
    cout<<setw(30)<<showpoint<<setprecision(10)<<d<<"----L4"<<'\n';
    //setbase(name)设置进制 
    cout<<setw(30)<<setbase(16)<<100<<"---L5"<<endl;;
    cout<<setbase(10)<<16*6+4<<endl;
}