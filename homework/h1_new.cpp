#include <iostream>
using namespace std;
int ex1()
{
    int *p=new int (3);//指针p指向3的地址
    //*p=3;
    int q=*new int;//取值给p
    // int b=new int ;
    // b=1;
    //cout<<b<<endl;
    //不行,new出来的原本就是指针（地址）
    q=1;
    cout<<q<<endl;
    return *p;
}

int* ex2()//输出为指针的意思
{
    int *q=new int [3];
    for(int i=0;i<3;i++)
    {
        q[i]=i;
        //cin>>q[i];
    }
    return q;//返回的是指针
} 
struct student
{
    string name;
    int score;

};

student* ex3()
{
    //用一个结构体指针接住结构体数组的首地址完成赋值
    //对于结构体指针，方便
    student *stlist=new student[3]{{"abc",90},{"abc",79},{"ccd",93}};
    return stlist;
}
int main()
{
    int e1=ex1();
    cout<<"e1: "<<e1<<endl;

    int *e2=ex2();
    for(int i=0;i<3;i++)
    cout<<e2[i]<<endl;

    student *st1=ex3();
    for(int i=0;i<3;i++)
    cout<<st1[i].name<<" "<<st1[i].score<<endl;

    return 0;
}
/*
1
e1: 3
0
1
2
abc 90
abc 79
ccd 93
*/