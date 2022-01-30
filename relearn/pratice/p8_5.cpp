#include <iostream>
using namespace std;
template <class T,int MAX>
class Stack
{
    T elem[MAX];
    int top;
    public:
    Stack(){top=0;}
    bool empty();
    bool full();
    void setempty();
    void push(T);
    T pop();
};
//函数实现
template <class T,int MAX>
bool Stack<T,MAX>::empty()//判断是否空栈
{
    if(top<=-1)return 1;
    else return 0;
}
template <class T,int MAX>
bool Stack<T,MAX>::full()//判断是否满栈
{
    if(top>MAX-1)return 1;
    else return 0;
}
template <class T,int MAX>
void Stack<T,MAX>::setempty()//将栈置空
{top=0;}
template <class T,int MAX>
void Stack<T,MAX>::push(T e)//输入
{
    if(full())
    {
        cout<<"栈已满,无法输入"<<endl;
        return;
    }
    elem[++top]=e;//
}
template <class T,int MAX>
T Stack<T,MAX>::pop()//输出
{
    if(empty())
    {
        cout<<"栈已空,无法输出"<<endl;
        return 0;
    }
    return elem[top--];//
}
//主函数
int main()
{
    Stack<int,10>istack;
    Stack<char,10>cstack;
    istack.setempty();
    cstack.setempty();
    for(int i=0;i<10;i++)
    {istack.push(i+2);}
    cstack.push('A');
    cstack.push('B');
    cstack.push('C');
    cstack.push('D');
    cstack.push('S');
    cstack.push('A');
    cstack.push('G');
    cstack.push('B');
    cstack.push('K');
    for(int i=0;i<10;i++)
    {
        cout<<istack.pop()<<endl;
        cout<<cstack.pop()<<endl;
    }
}