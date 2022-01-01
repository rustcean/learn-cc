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
class Graduate:virtual public Student//虚基类,保证派生类只保留一组有效数据
{
    float wage;
    public:
    Graduate(string,int,float,float );
    void display();
};
Graduate::Graduate(string nam,int n,float s,float w)
:Student(nam,n,s){wage=w;}
void Graduate::display()
{
    Student::display();//要在这里加一个Student
    cout<<"wages:"<<wage<<endl;
}
int main()
{
    Student s1("li",1200,87.5);
    Graduate g("Wang",2001,98.5,1000);
    Student *pt=&s1;
    pt->display();
    pt=&g;
    pt->display();//增加虚基函数就不只输出基类的内容
    return 0;
}
