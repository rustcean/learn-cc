#include <iostream>
#include <cstring>
using namespace std;
struct student
{
    int num;
    char name[20];
    float score[3];
};
int main()
{
    student stu;
    stu.num=8;
    strcpy(stu.name, "good boy");
    stu.score[0]=99.5;
    stu.score[1]=99.5;
    stu.score[2]=99.5;
    void print(student *);
    print(&stu);//这个不是取地址吗？
    return 0;
}
void print(student *p)
{
    printf("\tnum    :%d\n",p->num);
    printf("\tname   :%s\n",p->name);
    printf("\tscore1 :%f\n",p->score[0]);
    printf("\tscore2 :%f\n",p->score[1]);
    printf("\tnscore3:%f\n",p->score[2]);
}
