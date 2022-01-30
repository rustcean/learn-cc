#include <iostream>//证明static只是在定义之后,不会再定义,值可以改
using namespace std;
int main()
{
    //static a;//‘a’ does not name a type
    for(int i=0;i<2;i++)
    {
        static int a=0;//static只有在定义的位置保持不变,若先定义,再赋值,相当于赋值       
        //a=0;//
        a++;
        cout<<a<<endl;
    }
    return 0;
}