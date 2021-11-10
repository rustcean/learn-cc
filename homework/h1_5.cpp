#include <iostream>
struct student
{
    int num;
    float score;
    struct student *next;
};
int main()
{
    struct student a,b,c,*head;
    a.num=1001;
    a.score=90.5;
    b.num=1002;
    b.score=91.5;
    c.num=1005;
    c.score=94.5;
    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;//非常重要
    do
    {
        printf("%d %5.1f\n",head->num,head->score);
        head=(*head).next;//非常重要
    } while (head);
    
}