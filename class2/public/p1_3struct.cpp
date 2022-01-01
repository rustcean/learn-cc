#include <iostream>
#include <string>
using namespace std;
class Student
{
    public :
    Student(int n,string nam,char s)
    {
        num=n;
        name=nam;
        sex=s;
    }
    ~Student(){}
    protected:
    int num;
    string name;
    char sex;
};
class Student1:public Student
{
    public://竟然忘了吐血
    Student1(int n,string nam,char s,int a,string ad):Student(n,nam,s)
    {
        age=a;addr=ad;
    }
    void show()
    {
        cout<<"num: "<<num<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"sex: "<<sex<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"addr: "<<addr<<endl<<endl;
    }
    ~Student1(){}
    private:
    int age;
    string addr;
};
int main()
{
    Student1 s1(10,"Wang",'f',19,"Beijing");   
    s1.show();
    return 0;
}