//POJ 3750-链表方法
#include <iostream>
#include <cstdio>
using namespace std;
class Child
{
    public:
    char name[17];//保存名字
    bool ch;//用于后面的假性删除
    Child *next;
    void print()
    {printf("%s\n",name);}
    void gettrue()
    {ch=true;}
    void change()
    {ch=false;}
};
Child *head=NULL;
void add(Child *h)//添加
{
    Child *p=h;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    Child *w = new Child;
    scanf("%s",w->name);
    w->gettrue();
    p->next=w;
    w->next=NULL;    
}

int main()
{
    head=new Child;//头指针
    int n=0;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        add(head);
    }
    int w,s;
    scanf("%d,%d",&w,&s);
    Child *p=head;
    for(i=0;i<w;i++)//将指针移动到w处
    {
        p=p->next;
    }
    i=0;
    int j=0;
    while(i<n)
    {
        if(p->ch)//若未删除
        {
            j++;
            if(j==s)//如果算到s
            {
                p->print();
                p->change();
                i++;
                j=0;
            }
        }
        if(p->next==NULL)//转到头指针重新开始
        {
            p=head;
        }
        p=p->next;
        
    }
    return 0;
}
    // while(p!=NULL)
    // {
    //     p->print();
    //     p=p->next;
    // }