#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Book
{
    string name;
    float price;
    int num;
    Book *next;
};
struct Book *head=new Book;//生成指针用来指向new出来的地址

void addBook(struct Book *head);
void listBook(struct Book *head);
void findBook(struct Book *head);
void editBook(struct Book *head);
//void statBook();
//void sort(struct Book *head)
void menu();

int main()
{
    head->next=NULL;
    menu();
    
return 0;
}

void menu()
{
    cout<<"***图书管理系统***"<<endl;
    cout<<"   1.添加图书"<<endl;
    cout<<"   2.显示所有图书信息"<<endl;
    cout<<"   3.查找图书"<<endl;
    cout<<"   4.修改图书信息"<<endl;
    cout<<"   5.图书信息统计"<<endl;//功能等于2，没有加
    cout<<"   6.清除屏幕重置"<<endl;//
    cout<<"   7.排序"<<endl;//未加
    cout<<"   0.退出系统"<<endl;
    cout<<"***************************"<<endl;
    cout<<"请输入对应的标号，执行相应的功能"<<endl;
    unsigned int ch;//用来选择功能
    while(1)
    {
        cin>>ch;
        switch(ch)
        {
            case 1 :addBook(head);break;
            case 2 :listBook(head);break;
            case 3 :findBook(head);break;
            case 4 :editBook(head);break;
            case 5 :cout<<"wait，抱歉，未开放功能，请重新选择"<<endl;break;
            case 6 :cout<<"wait，抱歉，未开放功能，请重新选择"<<endl;break;
            case 7 :cout<<"wait，抱歉，未开放功能，请重新选择"<<endl;break;
            case 0 :exit(0);break;//正常退出程序，若为1则是非正常导致退出程序
            default : cout<<"选择出错，重新选择"<<endl;

        }
    }
}

void addBook(Book *head)
{
    Book *p=head;//
    while(p->next)//动态建立链表
    {
        p=p->next;
    }
    Book *book=new Book;//生成新的空间
    cout<<"输入图书名称"<<endl;
    cin>>book->name;/******出错******/
    cout<<"输入图书价格"<<endl;
    cin>>book->price;
    cout<<"输入图书数量"<<endl;
    cin>>book->num;

    p->next=book;
    book->next=NULL;
    system("clear");//系统执行clear--ubuntu下清屏
    cout<<"输入完成"<<endl;
    menu();
}
void listBook(Book *head)
{
    Book *p=head->next;
    cout<<"书有以下这些:"<<endl;
    while(p)
    {
        cout<<p->name<<" "<<p->price<<" "<<p->num<<endl;
        p=p->next;
    }
    cout<<"信息输出完成，请选择操作代码"<<endl;
    cout<<endl;
    menu();

}

void findBook(Book *head)
{
    cout<<"要输入书名还是序号？"<<endl;
    cout<<"书名按1,序号按2"<<endl;
    int a;
    cin>>a;
    if(a==1)
    {
        string name1;
        cout<<"输入要找的书名"<<endl;
        cin>>name1;//要查寻的书名
        bool x=true;//用来判断是否有书
        Book *p=head->next;
        while(p)
    {
        if(name1.compare(p->name)==0)//查询书名
        {
            cout<<"你要找的书如下："<<endl;
            cout<<p->name<<" "<<p->price<<" "<<p->num<<endl;
            x=false;
            break;
        }
        p=p->next;
    }
    if(x) cout<<"出错,没有这本书"<<endl;
    }
    else if(a==2)
    {
    cout<<"要查找第几本书:";
    int i,j;
    cin>>i;
    j=i;
    Book *p=head->next;
    while(--i)
    {
        p=p->next;
    }
    cout<<"第"<<j<<"本书为："<<endl;
    cout<<p->name<<" "<<p->price<<" "<<p->num<<endl;
    cout<<"完成，请选择操作代码"<<endl;
    }
    else cout<<"error"<<endl;
    cout<<endl;
    menu();
}
void editBook(Book *head)
{
    cout<<"***请输入要修改的书名***"<<endl;
        string name2;
        cin>>name2;
        bool x=true;
        Book *p=head->next;
        while(p)
    {
        if(name2.compare(p->name)==0)//用来寻找要修改的书
        {cout<<p->name<<" "<<p->price<<" "<<p->num<<endl;x=false;break;}
        p=p->next;
    }
    if(x)cout<<"没有你要修改的书"<<endl;
    cout<<"请进行修改"<<endl;
    cout<<"修改图书名称"<<endl;
    cin>>p->name;
    cout<<"修改图书价格"<<endl;
    cin>>p->price;
    cout<<"修改图书数量"<<endl;
    cin>>p->num;
    system("clear");//系统执行clear--ubuntu下清屏
    cout<<"修改完成"<<endl<<endl;
    listBook(head);//执行listBook，确认修改成功
}
