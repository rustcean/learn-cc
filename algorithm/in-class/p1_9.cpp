#include <ostream>
using namespace std;
class D
{
    public:
    int message;
    char chart[10];
    D *next;
    void print();
    void getin();
};
void D::print()
{
    printf("数量: %d\n",message);
    printf("%s\n",chart);
}
void D::getin()
{
    printf("请输入数目:");
    scanf("%d",&message);
    printf("请输入信息:");
    scanf("%s",chart);
}
int main()
{

}


// //课堂中的链表操作
// struct Linknode
// {
//     int a;
//     Linknode *next;
// };
// void josephus(int n,int start,int m)
// {
//     Linknode *tail, *p, *ptr;
//     int i;
//     tail=CreateCir(n);//生成以tail为尾指针的循环链表
//     ptr=tail;
//     p=tail->next;
//     for(i1;i<start;i++)
//     {
//         ptr=p;p=p->next;
//     }
//     while(ptr!=p)
//     {
//         cout<<p->data<endl;//输出位置好
//         ptr->next=p->next;//删除已输出的结点
//         delete p;
//         p=ptr->next;
//         for(i=1;i<m;i++)
//         {
//             ptr=p;p=p->next;
//         }
//     }
//     cout<<p->data<<endl;
//     delete p;//最后的一位特殊删除,避免runtime error
// }



/*



*/