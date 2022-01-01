#include <iostream>
#include <string>
using namespace std;
class Student
{
    public:
    Student(int n,string nam,char s):num(n),name(nam),sex(s)
    {
        cout<<"Constructor called."<<endl;
    }
    ~Student()//析构函数,可以解析定义的变量
    {
        cout<<"Destructor called."<<num<<endl;//先定义的变量后析构
    }
    void display();
    private:
    int num;
    string name;
    char sex;
};
void Student::display()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl<<endl;
}
int main()
{
    Student s1(10010,"Wang_li",'f');
    s1.display();
    Student s2(10011,"Zhang_fang",'m');
    s2.display();
    return 0;
}