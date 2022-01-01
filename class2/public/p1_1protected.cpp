#include <iostream>
#include <string>

using namespace std;

class Student
{
    public:
    protected://受保护的成员,在子类中可以被引用,
    int num;
    string name;
    char sex;
};
class Student1:protected Student
{
    public:
    void getvalue_1();
    void display1();
    private:
    int age;
    string addr;
};
void Student1::getvalue_1()
{
    cout<<"num name sex:";
    cin>>num>>name>>sex;
    cout<<"age addr :";
    cin>>age>>addr;
    cout<<endl;
}
void Student1::display1()
{
    cout<<"num: "<<num<<endl;//引用父类中的保护成员
    cout<<"name: "<<name<<endl;//
    cout<<"sex: "<<sex<<endl;//
    cout<<"age: "<<age<<endl;
    cout<<"addr: "<<addr<<endl;
}

int main()
{
    Student1 s1;
    s1.getvalue_1();
    s1.display1();
    return 0;
}