#include "Tree.h"
#include <fstream>
#include <cstring>
using namespace std;

#define First_stu_number 10
string filename="text";


//功能1-从终端读取信息做成Node数组,然后生成树
void gettree(bsTree &t)
{
    Node v[First_stu_number+2];
    cout<<"请输入十组学生信息:"<<endl;
    for(int i=0;i<First_stu_number;i++)
    {
        cin>>v[i].stu_name>>v[i].stu_number>>v[i].stu_sex>>
        v[i].phonenumber>>v[i].stu_address>>v[i].d_date.year>>v[i].d_date.month;
    }
    //生成树
    t.createbsTree(v,First_stu_number);
}

//功能2-插入学生信息
void Insert(bsTree &t)
{
    cout<<"请输入要插入的学生信息:"<<endl;
    Node n;
    cin>>n.stu_name>>n.stu_number>>n.stu_sex>>
        n.phonenumber>>n.stu_address>>n.d_date.year>>n.d_date.month;
    t.Insert(n);
}

//功能3-删除学生信息
void Delete(bsTree &t)
{
    cout<<"请输入要删除的学生信息:"<<endl;
    Node n;
    cin>>n.stu_name>>n.stu_number>>n.stu_sex>>
        n.phonenumber>>n.stu_address>>n.d_date.year>>n.d_date.month;
    t.remove(n);
    system("clear");
}

//功能4-文件读取通讯录信息
int gettree_file(bsTree &t)
{
    Node v[50];
    ifstream infile(filename,ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    string ch; //暂存
    int num=0;
    while (getline(infile,ch))
    {
        //"姓名\t"<<"学号\t"<<"性别\t"<<"电话号码\t"<<"地址\t"<<"出生日期"
        Node n;
        int i=0;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){n.stu_name+=ch[i];}
            else break;
        }
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){n.stu_number+=ch[i];}
            else break;
        }
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){n.stu_sex+=ch[i];}
            else break;
        }
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){n.phonenumber+=ch[i];}
            else break;
        }
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){n.stu_address+=ch[i];}
            else break;
        }
        string y="";
        string m="";
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){y+=ch[i];}
            else break;
        }
        i++;
        for(;i<ch.length();i++){
            if(ch[i]!=' '){m+=ch[i];}
        }
        //存储
        // cout<<n.stu_name<<"\t"<<n.stu_number<<"\t"<<n.stu_sex<<"\t"<<
        // n.phonenumber<<"\t"<<n.stu_address<<"\t"<<n.d_date.year<<"-"<<n.d_date.month<<endl;

        n.d_date.year=atoi(y.c_str());
        n.d_date.month=atoi(m.c_str());

        v[num].stu_name=n.stu_name;
        v[num].stu_number=n.stu_number;
        v[num].stu_sex=n.stu_sex;
        v[num].phonenumber=n.phonenumber;
        v[num].stu_address=n.stu_address;
        v[num].d_date.year=n.d_date.year;
        v[num].d_date.month=n.d_date.month;
        num++;
    }
    t.createbsTree(v,num);
    infile.close();
    return num;
}

//功能5-向文件写入
void Outtofile(bsTree &t)
{
    //
    ofstream outfile(filename,ios::out);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    string str=t.getall(t.root);
    outfile<<str;
    outfile.close();
}

//功能6-查找
void Find(bsTree &t)
{
    cout<<"输入要查找的学生的学号:"<<endl;
    string str;
    cin>>str;
    Node n;
    n.stu_number=str;
    Node *pr;
    Node *p=t.Search(n,pr);
    if(!p){cout<<"未找到"<<endl;return;}
    else{
        cout<<"信息:"<<endl;
        cout<<p->stu_name<<"\t"<<p->stu_number<<"\t"<<p->stu_sex<<"\t"<<
        p->phonenumber<<"\t"<<p->stu_address<<"\t"<<p->d_date.year<<"-"<<p->d_date.month<<endl;
    }
}

//功能7--输出所有学生信息
void PrintStu(bsTree &t)
{
    cout<<"姓名\t"<<"学号\t\t"<<"性别\t"<<"电话号码\t"<<"地址\t"<<"出生日期"<<endl;
    t.print(t.root);
}


//菜单函数
void menu(bsTree &t)
{
    cout<<"***学生通讯录系统***"<<endl;
    cout<<"   1.新建学生通讯录"<<endl;
    cout<<"   2.向学生通讯录插入学生信息"<<endl;
    cout<<"   3.在通讯录删除学生信息"<<endl;
    cout<<"   4.从文件中读取通讯录信息"<<endl;
    cout<<"   5.向文件写入学生通讯录信息"<<endl;
    cout<<"   6.在通讯录中查询学生信息"<<endl;//
    cout<<"   7.在屏幕中输出全部学生信息"<<endl;
    cout<<"   8.退出系统"<<endl;
    cout<<"***************************"<<endl;
    cout<<"请输入对应的标号，执行相应的功能"<<endl;
    unsigned int ch;//用来选择功能
    while(1)
    {
        cin>>ch;
        switch(ch)
        {
            case 1 :gettree(t);menu(t);break;
            case 2 :Insert(t);menu(t);break;
            case 3 :Delete(t);menu(t);break;
            case 4 :gettree_file(t);menu(t);break;
            case 5 :Outtofile(t);menu(t);break;
            case 6 :Find(t);menu(t);break;
            case 7 :PrintStu(t);menu(t);break;
            case 8 :exit(0);break;//正常退出程序，若为1则是非正常导致退出程序
            default : cout<<"选择出错，重新选择"<<endl;

        }
    }
}


int main()
{
    bsTree tree;
    menu(tree);
}