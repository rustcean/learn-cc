#include <iostream>
using namespace std;
#define N 3
class Student
{
    int num;       //学号
    int date[3];   //生日
    string name;   //名字
    string zhuanye;//专业
    string yuanxi; //院系
    string cla;  //班级
    string nianji  //年级
    public:
    Student();
    Student(string nian,string na,int n);
    void display();
    void get();
}

Student::Student()
{
    num=1;
    date[0]=2020;
    date[1]=10;
    date[2]=20;
    name="大一新生";
    zhuanye="人工智能";
    yuanxi="人工智能学院";
    cla="人工智能1班";
    nianji="大一";
}
Student::Student(string nian,string na,int n)
{
    nianji=nian;
    name=na;
    num=n;
    date[0]=2020;
    date[1]=10;
    date[2]=20;
    zhuanye="人工智能";
    yuanxi="人工智能学院";
    cla="人工智能1班";
}

void Student::display()
{
    cout<<"姓名:"<<name<<endl;
    cout<<"学号:"<<num<<endl;
    cout<<"生日:";
    for(int i=0;i<3;i++)
    {
        cout<<date[i];
    }
    cout<<"专业:"<<zhuanye<<endl;
    cout<<"年级:"<<nianji<<endl;

}
void Student::get()
{
    cout<<"姓名:";
    cin>>name;
    cout<<"学号:";
    cin>>num;
    cout<<"生日:";
    for(int i=0;i<3;i++)
    {
        cin>>date[i];
    }
    cout<<"专业:";
    cin>>zhuanye;
    cout<<"年级:";
    cin>>nianji;
    cout<<"学院:";
    cin>>xueyuan;

}
