#include <iostream>//虚基类的使用
#include <string>
using namespace std;
class Person
{
    public:
    Person(string nam,char s,int a)
    {name=nam;sex=s;age=a;}
    protected:
    string name;
    char sex;
    int age;
};
//设置虚基,只要在这里前写virtual
class Teacher :virtual public Person
{
    public:
    Teacher(string nam,char s,int a,string t)
    :Person(nam,s,a){title=t;}
    protected:
    string title;
};
class Student:virtual public Person
{
    public:
    Student(string nam,char s,int a,float sco)
    :Person(nam,s,a),score(sco){}
    protected:
    float score;
};
class Graduate:public Teacher,public Student
{
    public:
    //对于虚基类,要记得在这里写原来的基
    Graduate(string nam,char s,int a,string t,float sco,float w)
    :Person(nam,s,a),Teacher(nam,s,a,t),Student(nam,s,a,sco),wage(w){}
    void show()
    {
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"sex:"<<sex<<endl;
        cout<<"scor:"<<score<<endl;
        cout<<"title:"<<title<<endl;
        cout<<"wages:"<<wage<<endl;
    }
    private:
    float wage;
};
int main()
{
    Graduate g1("Wang_li",'f',24,"assistant",89.5,1200);
    g1.show();
    Person &p=g1;
    
    return 0;
}