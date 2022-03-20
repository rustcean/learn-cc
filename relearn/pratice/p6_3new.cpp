/***
 * new学习
*/
#include <iostream>
using namespace std;
class A
{
    public:
    virtual ~A(){cout<<"call A::~A()"<<endl;}
};
class B:public A
{
    char *buf;
    public:
    B(int i){buf=new char[i];}
    ~B()
    {
        delete [] buf;//释放
        cout<<"call B::~B()"<<endl;
    }
};
int main()
{
    A *a=new B(10);//释放
    delete a;
    return 0;
}