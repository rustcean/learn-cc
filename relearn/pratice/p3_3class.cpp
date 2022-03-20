/*类的向前声明
 *注意:虽然用了向前声明,但在提供一个完整的类之前,不能声明该类对象
*/
#include <iostream>
using namespace std;
//1
class Fred;   //向前声明
class Barney
{
    //Fred x;//错误,has incomplete type ‘Fred’
    public:
    Barney(){cout<<"banary called"<<endl;}
    void fun(){cout<<"barney called"<<endl;}
    Fred* x;
};
class Fred
{
    public:
    Fred(){cout<<"Fred called"<<endl;}
    void fun(){cout<<"Fred called"<<endl;}
    Barney c;//当类已经声明后,可以使用
    Barney *y;
};
/*
当使用向前引用生命时,只能使用被声明的符号,而不能涉及类的任何细节
*/
int main()
{
    Fred f1;
    Barney b1;
    f1.c.x=&f1;
    f1.c.x->c.x->fun();
    f1.y->x->fun(); 
    b1.x=&f1;
    f1.y=&b1;
    // f1.fun();
    // b1.fun();
    return 0;
}

