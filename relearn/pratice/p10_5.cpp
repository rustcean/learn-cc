#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Employee
{
    int number,age;
    char name[20];
    double sa1;
    public:
    Employee(){}
    Employee(int num,const char *nam,int a,double s)
    :number(num),age(a),sa1(s){strcpy(name,nam);}
    void display();
};
void Employee::display()
{
    cout<<number<<'\t'<<name<<'\t'<<age<<"\t"<<sa1<<endl;
}
int main()
{
    ofstream outfile("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::out);
    Employee e1(1,"张三",23,2320);
    Employee e2(2,"李四",32,3210);
    Employee e3(3,"王五",34,2220);
    Employee e4(4,"刘六",27,1220);
    outfile.write((char*)&e1,sizeof(e1));
    outfile.write((char *)&e2,sizeof(e1));
    outfile.write((char *)&e3,sizeof(e3));
    outfile.write((char *)&e4,sizeof(e4));
    outfile.close();
    ifstream infile("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::in);
    char n[sizeof(e1)];
    for(int i=0;i<4;i++)
    {
        infile.read(n,sizeof(e1));
        cout<<n<<endl;
    }
    infile.close();
    cout<<"\n"<<endl;
    outfile.open("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::out);
    Employee e5(3,"王五",40,2220);
    outfile.seekp(3*sizeof(e1));
    outfile.write((char *)&e5,sizeof(e1));
    outfile.close();
    // infile.open("/home/wnanqun/nanqun/learn-c++/relearn/pratice/001",ios::in);
    // for(int i=0;i<4;i++)
    // {
    //     infile>>n;
    //     cout<<n<<endl;
    // }
    // infile.close();
}