#include <iostream>
using namespace std;
   struct Student
{
    int num;
    char nam[20];
    char sex;
    float score;
}student1,student2;
int main()
{
 
    printf("%d\n",int(sizeof(student1)));
    student1=Student{ 102,"jane",'M',98.50 };//未初始化，需要重新定义为student型
    student2=student1;
    printf("number = %d\nname is %s\nscore = %f\n",student1.num,student1.nam,student1.score);
    printf("number = %d\nname is %s\nscore = %f\n",student2.num,student2.nam,student2.score);
    return 0;
}