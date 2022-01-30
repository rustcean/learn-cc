
/*
一个公司有经理,销售员,小时工,做一个基类,包含姓名,身份证号,其他的继承
*/
#include <iostream>
#include <string>
using namespace std;
class Employee
{
    public:
    Employee(string Name,string id):name(Name),Id(id){}
    string getName(){return name;}
    string getID(){return Id;}
    float getSalary(){return 0.0;}
    void print()
    {cout<<"姓名:"<<name<<"\t\t编号:"<<Id<<endl;}
    private:
    string name;
    string Id;
};
class Manager:public Employee
{
    public:
    Manager(string Name,string id,int week):Employee(Name,id)
    {WeeklySalary=week*1000;}
    float getSalary(){return WeeklySalary;}
    void print()
    {
        cout<<"经理:"<<getName()<<"\t\t编号:"<<getID()
        <<"\t\t总工资:"<<getSalary()<<endl;
    }
    private:
    float WeeklySalary;
};
class SaleWorker:public Employee
{
    public:
    SaleWorker(string name,string id,int profit,int x):Employee(name,id)
    {workMoney=BaseMoney+x*0.05*profit;}
    float getSalary(){return workMoney;}
    void print();
    private:
    float workMoney;
    float BaseMoney=800.0;
};
void SaleWorker::print()
{
    cout<<"销售员:"<<getName()<<"\t\t编号:"<<getID()
    <<"\t\t总工资:"<<getSalary()<<endl;
}

class HourWork:public Employee
{
    float HourMoney=100.0;
    float TotalMoney;
    public:
    HourWork(string name,string id,int h):Employee(name,id)
    {TotalMoney=HourMoney*h;}
    float getSalary(){return TotalMoney;}
    void  print()
    {cout<<"小时工:"<<getName()<<"\t\t编号:"<<getID()
    <<"\t\t 总工资:"<<getSalary()<<endl;}
};
int main()
{
    Manager m1("小名","1001",100.0);
    Employee e1=m1;
    cout<<e1.getSalary()<<endl;
    cout<<e1.getName()<<endl;
    cout<<"请输入工作周:";
    int week;
    cin>>week;
    Manager m("小王","11111",week);
    m.print();
    cout<<"请输入销售利润:";
    int profit;
    cin>>profit;
    cout<<"请输入销售件数:";
    int x;
    cin>>x;
    SaleWorker s("小李","22222",profit,x);
    s.print();
    cout<<"请输入工作小时:";
    int hour;
    cin>>hour;
    HourWork h("小何","33333",hour);
    h.print();
    return 0;

}