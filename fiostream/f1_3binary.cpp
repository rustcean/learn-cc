#include <fstream>
#include <iostream>
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
    student stud[3]=
    {
        "Li",1001,18,'f',
        "Fang",1002,19,'m',
        "Wang",1004,17,'f'
    };
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::binary);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        abort();//什么函数
    }
    for(int i=0;i<3;i++)
    {
        outfile.write((char *)&stud[i],sizeof(stud[i]));
    }
    outfile.close();
    return 0;
}