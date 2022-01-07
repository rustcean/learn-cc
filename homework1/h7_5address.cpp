#include <iostream>
#include <cstring>
#define NUM 2
using namespace std;
class Address
{
    public:
    char *name;//名字
    string addre;//地址
    int phonenum;//电话号码
    long birthday;//生日
    Address *next;//用来建立链表的
    Address()//默认构造函数
    {
        name=new char[30];
        addre="北京路";
        phonenum=12135;
        birthday=19000101;
    }
    ~Address()//释放new的空间
    {
        delete []name;
    }
    Address(const Address &a)//有参数的构造函数
    {
        strcpy(name,a.name);
        addre=a.addre;
        phonenum=a.phonenum;
        birthday=a.birthday;
    }
    friend ostream& operator<<(ostream&out,Address&a);
    friend istream& operator>>(istream&in,Address&a);
};


void lst(Address family[NUM]);//列出默认联系人

void menu();//菜单提供选项
void add(Address *head);//增加联系人
void list(Address *head);//列出联系人
void find(Address *head);

/*以下为运算符重载*/
ostream & operator<<(ostream&out,Address&a)
{
    out<<a.name<<":"<<a.addre<<":"<<a.phonenum<<":"<<a.birthday<<endl;
    return out;
}
istream& operator>>(istream&in,Address&a)
{
    cout<<"input name:";
    in>>a.name;
    cout<<"input address:";
    in>>a.addre;
    cout<<"input phonenumber:";
    in>>a.phonenum;
    cout<<"input birthday:";
    in>>a.birthday;
    return in;
}

Address *head=new Address;//生成一个类对象,并把地址给head
void menu()
{
    cout<<"****地址簿*****"<<endl;
    cout<<"   1.添加联系人"<<endl;
    cout<<"   2.显示所有联系人信息"<<endl;
    cout<<"   3.查找联系人"<<endl;
    cout<<"   4.修改联系人信息"<<endl;
    cout<<"   0.退出系统"<<endl;
    cout<<"****************"<<endl;
    cout<<"请输入对应的标号，执行相应的功能"<<endl;
    unsigned int ch;//用来选择功能
    while(1)
    {
        cin>>ch;
        switch(ch)
        {
            case 1 :add(head);break;
            case 2 :list(head);break;
            case 3 :find(head);break;
            case 0 :exit(0);break;//正常退出程序
            default : cout<<"选择出错，重新选择"<<endl;

        }
    }
}
void add(Address *head)
{
    Address *p=head;
    while(p->next)//动态建立链表
    {
        p=p->next;
    }
    Address *contacts=new Address;//生成新的空间
    // cout<<"输入联系人名称"<<endl;
    // cin>>contacts->name;/******出错******/
    // cout<<"输入联系人地址"<<endl;
    // cin>>contacts->addre;
    // cout<<"输入电话号码"<<endl;
    // cin>>contacts->phonenum;
    // cout<<"输入生日"<<endl;
    // cin>>contacts->birthday;
    // p->next=contacts;
    cin>>(*contacts);//已经重载>>运算符
    p->next=contacts;
    contacts->next=NULL;
    system("clear");//系统执行clear--ubuntu下清屏
    cout<<"输入完成"<<endl;
    menu();//重新进入菜单栏
}

void lst(Address family[NUM])
{
    for(int i=0;i<NUM;i++)
    cout<<family[i];
}

void list(Address*head)
{
    system("clear");//清屏
    cout<<"以下为普通联系人,可更改:"<<endl;
    Address *p=head->next;
    while(p)
    {
        cout<<(*p);
        p=p->next;
    }
    cout<<endl;
    cout<<"信息输出完成，请选择操作代码"<<endl;
    menu();

} 

void find(Address*head)
{
    system("clear");//清屏
    cout<<"input name:";
    char *name1=new char[30];//需要给它分配空间,不然会出错
    cin>>name1;
    bool x=true;//用来判断有无联系人的
    Address *p=head->next;
    while(p)
    {
        if(strcmp(p->name,name1)==0)
        {
        cout<<"该联系人的信息为:"<<endl;
        cout<<(*p);
        x=false;
        }
        p=p->next;
    }
    if(x){cout<<"没有该联系人"<<endl<<endl;}
    menu();
}

int main()
{
    Address family[NUM];//用来存放默认联系人,以下为联系人内容:
    strcpy(family[0].name,"梅小姐");
    family[0].addre="我的家里";
    family[0].phonenum=9920;
    family[0].birthday=20201216;
    strcpy(family[1].name,"肖老师");
    family[1].addre="大学城";
    family[1].phonenum=100000;
    family[1].birthday=2020001;
    cout<<"默认联系人:"<<endl;
    lst(family);
    head->next=NULL;
    menu();
    return 0;
}