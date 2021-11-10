#include <iostream>    //循环但失败了
using namespace std;
int main()
{
    char c;
    
    for(;(c=getchar())!='\n'; );
    {
        cout<<c<<endl;
    }
    return 0;
}