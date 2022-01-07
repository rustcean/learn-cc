#include <iostream>
using namespace std;
class Stu
{
    int a;
    public:   
    virtual void display(); 
    
    Stu(int x=0);
};
void Stu::display()
{
    cout<<a<<endl;
    cout<<"Stu"<<endl;
}
Stu::Stu(int x):a(x){}

class Tea:public Stu
{
    int b;
    public:
    virtual void display();
    //虽然在这里是private但在基类是public所以这里是public来使用
    
    void get();
    Tea(int x=0,int y=0):Stu(x),b(y){}
};
void Tea::display()
{
    cout<<b<<endl;
    cout<<"Tea"<<endl;
}
void Tea::get()
{
    display();
}
int main()
{
    Stu *p;
    Stu s1(5);
    Tea t1(2,3);
    p=&s1;
    p->display();
    p=&t1;
    p->display();
}

