//图书管理系统2.0版
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//结构体定义
struct Book
{
    string name;
    float price;
    int num;
    Book *next;
};
//全局变量指针
struct Book *head=new Book;//生成指针用来指向new出来的地址
//函数定义
void addBook(struct Book *head);//外部添加一本数
void listBook(struct Book *head);//列出所有的书
void findBook(struct Book *head);//查找一本书
void editBook(struct Book *head);//修改一本已知的书的信息
void setBook(struct Book *head,string n,float p,int);//内部设置
void deleteBook(struct Book *head);//删除一本书
//void statBook();
//void sort(struct Book *head)
void menu();
//主函数
int main()
{
    head->next=NULL;
    setBook(head,"xiao",120,4);
    setBook(head,"华丽户少",1300,3);
    setBook(head,"三体",60,3);   
    menu();
    
return 0;
}
//函数实现
void menu()
{
    cout<<"***图书管理系统***"<<endl;
    cout<<"   1.添加图书"<<endl;
    cout<<"   2.显示所有图书信息"<<endl;
    cout<<"   3.查找图书"<<endl;
    cout<<"   4.修改图书信息"<<endl;
    cout<<"   5.图书信息统计"<<endl;//功能等于2，没有加
    cout<<"   6.删除图书"<<endl;
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
            case 6 :deleteBook(head);break;
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

    p->next=book;//将书连接上链表
    book->next=NULL;//此结点的next设置为NULL
    system("clear");//系统执行clear--ubuntu下清屏
    cout<<"输入完成"<<endl;
    menu();
}
void listBook(Book *head)
{
    system("clear");//系统执行clear--ubuntu下清屏
    if(head->next==NULL)
    {cout<<"还没有书"<<endl;menu();}
    else
    {
        Book *p=head->next;
        cout<<"书有以下这些:"<<endl;
        cout<<"书名\t\t价格\t数目"<<endl;
        while(p)
        {
            cout<<p->name<<"\t\t"<<p->price<<"\t"<<p->num<<endl;
            p=p->next;
        }
        cout<<endl;
        cout<<"信息输出完成，请选择操作代码"<<endl;
        menu();
    }

}
void findBook(Book *head)
{
    system("clear");//系统执行clear--ubuntu下清屏
    if(head->next==NULL)
    {
        cout<<"出错,没有可查找的内容"<<endl;
        menu();
    }
    else
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
                    cout<<"书名:"<<p->name<<endl;
                    cout<<"价格:"<<p->price<<endl;
                    cout<<"数量:"<<p->num<<endl;;
                    x=false;
                    break;
                }
                p=p->next;
            }
        if(x) cout<<"没有这本书"<<endl;
        }
        else if(a==2)
        {
            cout<<"要查找第几本书:";
            int i,j;
            cin>>i;
            j=i;
            i-=1;
            Book *p=head->next;
            while(p->next)
            {
                p=p->next;
                --i;
            }
            if(i!=0)
            {
                cout<<"输入的数字太大,库中没有这么多书!"<<endl;
            }
            else 
            {
                cout<<"第"<<j<<"本书为："<<endl;
                cout<<"书名:"<<p->name<<endl;
                cout<<"价格:"<<p->price<<endl;
                cout<<"数量:"<<p->num<<endl;;
                cout<<endl;
                cout<<"完成，请选择操作代码"<<endl;
            }
        }
        else cout<<"error"<<endl;
        cout<<endl;
        menu();
    }
}
void editBook(Book *head)
{
    if(head->next==NULL)
    {
        system("clear");//系统执行clear--ubuntu下清屏
        cout<<"没有可修改的内容"<<endl;
        menu();
    }
    else
    {        
        cout<<"***请输入要修改的书名***"<<endl;
        string name2;
        cin>>name2;
        bool x=true;
        Book *p=head->next;
        while(p)
        {
            if(name2.compare(p->name)==0)//用来寻找要修改的书
            {
                cout<<p->name<<" "<<p->price<<" "<<p->num<<endl;
                x=false;
                break;
            }
            p=p->next;
        }
        if(x)
        {
            system("clear");//系统执行clear--ubuntu下清屏
            cout<<"没有你要修改的书"<<endl;
            cout<<"请在菜单栏选择添加"<<endl<<endl;
            menu();
        }
        else if(!x)
        {
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
        
    }
}
void setBook(Book *head,string nam,float pr,int n)
{
    Book *p=head;
    while (p->next)
    {
        p=p->next;
    }
    Book *book=new Book;
    book->name=nam;
    book->num=n;
    book->price=pr;
    p->next=book;
    book->next=NULL;
}
void deleteBook(Book *head)
{
    if(head->next==NULL)
    {cout<<"没有可删除的内容"<<endl;menu();}
    else
    {        
        cout<<"请选择要删除的书的名字:"<<endl;
        string name1;
        cin>>name1;
        bool x=true;//用来判断是否有书
        Book *p=head;
        Book *pt;//用来删除
        while(p)
        {
            if(name1.compare(p->name)==0)//查询书名
            {
                cout<<"书的信息:"<<endl;
                cout<<"书名:"<<p->name<<endl;
                cout<<"价格:"<<p->price<<endl;
                cout<<"数量:"<<p->num;
                x=false;//
                break;
            }
            pt=p;
            p=p->next;
        }
        if(x) cout<<"出错,没有这本书"<<endl;
        else if(!x)
        {
            cout<<"请确认是否删除(y/n):";
            char s;
            cin>>s;
            if(s=='y'||s=='Y')
            {
                if(p->next==NULL)
                {
                    p=pt;//向前指向一位
                    pt=p->next;//指向原来的p
                    p->next=NULL;
                    delete  pt;//释放空间
                    cout<<"删除完成"<<endl;
                }
                else 
                {
                    p=pt;//向前退一格
                    pt=p->next;//指向原来的p
                    p->next=pt->next;//next指向原来的p的下一格
                    delete pt;//释放空间
                    cout<<"删除完成"<<endl;
                }
                
            }
            else 
            {
                cout<<"您已取消"<<endl;
            }
        }
        menu();
    }
    
}







