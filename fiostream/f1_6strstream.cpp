/*
*str流的学习,它的类可以直接使用<<对str类型的数据进行输入,意义性感觉不是很大,不过也还不错
*这里:ends为'\0'的意思
*str下的char数组与普通的char数组不太一样

*/


#include <strstream>
#include <iostream>
using namespace std;
struct student
{
    int num;
    char name[20];
    float score;
};
int main()
{
    student stud[3]={
        1001,"li",78.9,
        1002,"wang",78,
        1004,"fang",90 };
    char c[50];
    ostrstream strout(c,40);
    for(int i=0;i<3;i++)
       strout<<" "<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score;
    strout<<ends;  //C++的I/o操作符,插入一个'\0'
    cout<<"array c:"<<c<<endl;
    return 0;


    //注意,这个与char数组有不同的地方
    // char  a[20]="good";
    // cout<<a<<end;
    /*char数组这样数输不出来的,首先,a是指针来着,没办法直接数,*/
}
