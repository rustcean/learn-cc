#include <iostream>
using namespace std;

//输出函数xx    
template <class numtype>
void print(numtype x)
{
    cout<<x<<endl;
}

int main()
{
    print(5);
    return 0;
}


