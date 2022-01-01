#include <iostream>
#include <string>
using namespace std;
class Student
{
    int num;
    string name;
    float score;
    public:
    Student(string nam,int n,float s);
    virtual void display();//增加虚基函数,后的函数,被本类的指针指向时可以覆盖本类同名函数
};
Student::Student(string nam,int n,float s)
{
    name=nam;
    num=n;
    score =s;
}
void Student::display()
{
    cout<<"name:"<<name<<endl;
    cout<<"num:"<<num<<endl;
    cout<<"score:"<<score<<endl;
}
class Mate
{
    Student s;
    public:
    Mate(string nam,int n,float s);
    void display();
};
Mate::Mate(string nam,int n,float s)
:s(nam,n,s){}
void Mate::display()
{
    s.display();
}
int main()
{
    Mate m1("li",18,89.5);
    m1.display();
    return 0;
}