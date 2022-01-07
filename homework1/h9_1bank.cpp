#include <iostream>
#include <cstring>
using namespace std;
class Bank
{
    float money;
    char password[20];
    string name;
    public:
    Bank(string nam="无",float m=0 ,char *p=NULL);//有参构造函数
    Bank(Bank &b1);//深拷贝构造函数
    void set_Pass();//密码设置
    void getin_pass();//进入
    void display();//输出帐号信息
    void addinfo(Bank &b);//记录转账信息
    void menu();//菜单
    ~Bank(){cout<<"called"<<endl;}
};   
//以下代码实现
Bank::Bank(string nam,float m,char *x)
{
    name=nam;
    money=m;
    strcpy(password,x);
}
Bank::Bank(Bank &b1)
{
    name=b1.name;
    money=b1.money;
    strcpy(password,b1.password);
}
//输出基本信息
void Bank::menu()
{
    int ch;
    cout<<"****欢迎登录*****"<<endl;
    cout<<"                "<<endl;
    cout<<"   1.查看信息     "<<endl;
    cout<<"   2.修改密码     "<<endl;
    cout<<"   0.退出        "<<endl;
    cout<<"*****************"<<endl;
    cout<<endl<<"请输入相应的数字执行相应的功能"<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:display(); break;
    case 2:set_Pass();break;
    case 0:break;
    default: cout<<"出错,重新输入:";
    }
}
void Bank::display()
{
    cout<<endl;
    cout<<"姓名:"<<name<<endl;
    cout<<"余额:"<<money<<endl;
    cout<<endl;
}
//收录转账信息并输出
void Bank::addinfo(Bank &b)
{
    float x=0;
    cout<<"您当前用户余额为:"<<money<<endl;
    cout<<"需要向她/他转账多少钱(单位:元):";
    cin>>x;
    if(x>money)cout<<"错误,您输入的金额超出您的余额!"<<endl;
    if(x>0&&x<money)
    {
        money-=x;
        b.money+=x;
        cout<<"转账成功"<<endl;
        cout<<"您当前的余额为:"<<money<<endl;
    }
}
//进入
void Bank::getin_pass()
{
    cout<<"请输入密码登录:";
    string ch;
    cin>>ch;
    if(ch.compare(password)==0)
    {
        cout<<"密码正确"<<endl;
        menu();
    }
    else cout<<"密码错误"<<endl;
}
//设置密码
void Bank::set_Pass()
{
    char *p;
    cout<<"输入密码:";
    cin>>*p;
    strcpy(password,p);
    cout<<"密码设置成功"<<endl;
    cout<<"请重新登录"<<endl;
    getin_pass();
}
//主函数
int main()
{
    Bank b1("nan",1200,"1234");
    Bank b2(b1);
    cout<<"她的账户信息为:"<<endl;
    b2.display();
    b1.getin_pass();
    b1.addinfo(b2);
    cout<<"她的账户信息为:"<<endl;
    b2.display();
    return 0;
}