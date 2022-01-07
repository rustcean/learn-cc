#include <iostream>
//此处不能有using namespace std
//会使max函数不知道应该用std模式还是函数模板
//也就是二意性
template <typename T>
T max(T a,T b)
{return a>b?a:b;}
int main()
{
    std::cout<<"Max(3,5) is "<<max(3,5)<<std::endl;
    std::cout<<"max('y','e') is "<<max('y','e')<<std::endl;
    std::cout<<"max(9.3,0.5) is "<<max(9.3,0.5)<<std::endl;
    return 0;
}