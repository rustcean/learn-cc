#include <iostream>
#include <fstream>
using namespace std;
struct student
{
    char name[20];
    int num;
    int age;
    char sex;
};

int main()
{
    student stud[3];
    int i;
    ifstream infile("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::binary);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        abort();//中止程序执行，直接从调用的地方跳出
    }
    for(i=0;i<3;i++)
    // infile.read((char*)stud,sizeof(stud));
    infile.read((char*)&stud[i],sizeof(stud[i]));
    
    infile.close();
    for(i=0;i<3;i++)
    {
        cout<<"No."<<i+1<<endl;
        cout<<"name:"<<stud[i].name<<endl;
        cout<<"num:"<<stud[i].num<<endl;
        cout<<"age:"<<stud[i].age<<endl;
        cout<<"SEX:"<<stud[i].sex<<endl;
    }
    return 0;
}




