#include <iostream>
using namespace std;
class Person
{
    string name;
    int age;
    string sex;
    public:
    Person();                       //默认构造函数
    Person(string n,int a,string s);//构造函数
    int get_age();                  //age获取
    string get_name();              //name获取
    string get_sex();               //sex获取
    void getin_age();               //age外部输入
    void getin_name();              //name外部输入
    void getin_sex();               //sex外部输入
    void set_age(int a);            //age内部设置
    void set_name(string n);        //name内部设置
    void set_sex(string s);         //sex内部设置
};
//以下为函数实现
Person::Person()
{
    name="梅小姐";
    age=18;
    sex="女";
}
Person::Person(string n,int a,string s)
{
    name=n;
    age=a;
    sex=s;
}
int Person::get_age()
{return age; }
string Person::get_name()
{return name;}
string Person::get_sex()
{return sex;}
void Person::getin_age()
{
    cout<<"please input the age of the person:";
    cin>>age;
}
void Person::getin_name()
{
    cout<<"please input the name of the person:";
    cin>>name;
}
void Person::getin_sex()
{
    cout<<"please input the sex of the person:";
    cin>>sex;
}
void Person::set_age(int a)
{age=a;}
void Person::set_name(string n)
{name=n;}
void Person::set_sex(string s)
{sex=s;}
//以下为测试
/*
int main()
{
    Person p1;
    cout<<p1.get_name()<<":"<<p1.get_age()<<"岁:"<<p1.get_sex()<<"性"<<endl;
    Person p2("啊七",18,"男");
    cout<<p2.get_name()<<":"<<p2.get_age()<<"岁:"<<p2.get_sex()<<"性"<<endl;
    p1.set_name("小七");
    p1.set_age(15);
    p1.set_sex("男");
    p2.getin_name();
    p2.getin_age();
    p2.getin_sex();
    cout<<p1.get_name()<<":"<<p1.get_age()<<"岁:"<<p1.get_sex()<<"性"<<endl;
    cout<<p2.get_name()<<":"<<p2.get_age()<<"岁:"<<p2.get_sex()<<"性"<<endl;    
    return 0;
}
*/