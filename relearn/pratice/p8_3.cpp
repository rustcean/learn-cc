/**
 * 特化:原本的模板功能不足时,特化出新的功能,--感觉-多态
 * 类型转换:
 * 
*/
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
T Max(T a,T b)
{return a>b?a:b;}
// 特化
//template <>返回类型 函数名<特化的数据类型>(参数表){}
template<>char*Max<char *>(char *a,char *b)
{
    return (strcmp(a,b)>=0)?a:b;
}
int main()
{
    float c=5.1,d=3.2;
    cout<<"2,3的最大值是:"<<Max(2,3)<<endl;
    cout<<"c,d的最大值是:"<<Max(c,d)<<endl;
    cout<<Max("xbv","xyce")<<endl;
    cout<<"\n\n";
    cout<<"类型转换:"<<endl;
    double a=2,b=3.4;
    cout<<Max(double(2),3.2)<<endl;;
    cout<<Max(float(a),c)<<endl;
    cout<<Max<int>('a',3)<<endl;
    return 0;
}