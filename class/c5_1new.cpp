#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    public:
    int sum();
    Student(int m,int e,int n,char *na):math(m),english(e),num(n),name(na){}
    Student(int m=0,int e=0);
    Student(char *);
    void show();
    void ccopy(char *s);
    private:
    int math;
    int english;
    char *name;
    int num;
};
Student::Student(int m,int e)
{
    math=m;
    english=e;
}
Student::Student(char *p)
{
    name=p;
}
int Student::sum()
{
    return math+english;
}

void Student::show()//实现将char*的打印
{
    cout<<"姓名:";
    int length=strlen(name);//测量它的长度
    for(int i=length;i>0;i--)//逐个打出来
    cout<<*(name+length-i);
    cout<<endl;
}

void Student::ccopy(char *s)
{

    int length=strlen(s);
    name=new char[length+1];
    strcpy(name,s); 
}

int main()
{
    Student s1((char*)"zhang");//只读了一个值
    s1.show();
    s1.ccopy((char*)"xinxianxiaoshesssss");//
    s1.show();
    return 0;
}














