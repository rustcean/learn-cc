/*
 *学习直接的fstream和seekg函数等
 *ios::beg开头
 *
 *
*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int SIZE=5;
struct student
{
    int num;
    char name[20];
    float score;
};

int main()
{
    int i;
    student stud[SIZE]=
    {
        1001,"li",85,
        1002,"fang",97.5,
        1004,"wang",54,
        1006,"tan",76.5,
        1010,"ling",96
    };
    fstream iofile("/home/wnanqun/nanqun/learn-c++/fiostream/001",ios::in|ios::out|ios::binary);
    //定义iofile并且要有输入输出二进制流对象的功能
    if(!iofile)
    {
        cerr<<"open error!"<<endl;
        abort();//结束跳出
    }
    for(i=0;i<SIZE;i++)
    iofile.write((char*)&stud[i],sizeof(stud[i]));
    //写入五个消息内容
    student stud1[SIZE];
    for(i=0;i<SIZE;i+=2)//注意这里是+=2
    {
        iofile.seekg(i*sizeof(stud[i]),ios::beg);
        //距离开头 i*stud[0]个大小 移动文件读取用的指针,只有stud[0]stud[3]stud[5]的数据读到了
        iofile.read((char*)&stud1[i/2],sizeof(stud1[0]));
        //对stud1读入数据,因为是i/2所以读到stud1[0],stud1[1]stud[2]中
        cout<<stud1[i/2].num<<" "<<stud1[i/2].name<<" "<<stud1[i/2].score<<endl;
        //输出数据
    }
    cout<<"\n"<<endl;
    stud[2].num=1012;
    strcpy(stud[2].name,"Wu");
    stud[2].score=60;
    iofile.seekp(2*sizeof(stud[0]),ios::beg);//定位于第三个学生的数据的开头
    iofile.write((char*)&stud[2],sizeof(stud[2]));//更新第三个学生的数据
    iofile.seekg(0*sizeof(stud[0]),ios::beg);//定位到开头的位置
    for(i=0;i<SIZE;i++)
    {
        iofile.read((char*)&stud[i],sizeof(stud[0]));
        cout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<endl;
    }
    iofile.close();
    return 0;
}