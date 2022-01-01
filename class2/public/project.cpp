#include <iostream>
using namespace std;
class Student
{
    public:
    void get_value()
    {cin>>num>>name>>sex;}
    void display()
    {
        cout<<"num: "<<num<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"sex: "<<sex<<endl;
    }
    private://私有成员,无法被子类直接引用
    int num;
    string name;
    char sex;//写成指针会发生核心转存
};
class Student1:public Student
{
    public:
    void get_value_1()
    {cin>>age>>addr;}
    void display_1()
    {
        display();//注意父类中的私有成员无法在子类中引用,但可以通过公有函数来引用
        cout<<"age: "<<age<<endl;
        cout<<"addr: "<<addr<<endl;
    }
    private:
        int age;
        string addr;
};