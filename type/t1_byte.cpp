#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n_int=INT_MAX;short n_short=SHRT_MAX;
    long n_long=LONG_MAX;long long n_llong=LLONG_MAX;
    cout<<"int is "<<sizeof(int)<<" bytes."<<endl;
    cout<<"short is " <<sizeof n_short<<" bytes."<<endl;
    cout<<"long is "<<sizeof(long)<<" bytes."<<endl;
    cout<<"long long is "<<sizeof(n_llong)<<" bytes."<<endl;
    cout<<"Maximum values:"<<endl;
    cout<<"int:"<<n_int<<endl;
    cout<<"short:"<<n_short<<endl;
    cout<<"long:"<<n_long<<endl;
    cout<<"llong:"<<n_llong<<endl;
    cout<<"Minimum values:"<<INT_MIN<<endl;
    cout<<"Bits per byte:"<<CHAR_BIT<<endl;
    char n_char=CHAR_MAX;
    cout<<"char is "<<sizeof(char)<<" bytes."<<endl;
    cout<<"Maximum values is "<<CHAR_MAX<<endl;
    float n_float=__FLOAT_WORD_ORDER;
    cout<<n_float<<endl;
    return 0;
}