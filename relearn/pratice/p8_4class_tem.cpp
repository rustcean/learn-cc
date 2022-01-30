#include <iostream>
using namespace std;
template <class T,int MAXSIZE>
class Stack
{
    T elem[MAXSIZE];
    int top;//
    public:
    Stack(){top=0;}
    void push(T e);
    T pop();
    bool empty()
    {
        if(top<=-1)return 1;//
        else return 0;
    }
    void setEmpty()//置空
    {top=0;}
    bool full()//判断是否满了
    {
        if(top>=MAXSIZE-1)return 1;
        else return 0;
    }
};
//函数实现
template<class T,int MAXSIZE>
void Stack<T,MAXSIZE>::push(T e)
{
    if(full())//如果满了,就说满了并退出
    {cout<<"栈已满,不能再添加元素!"<<endl;return;}
    elem[++top]=e;//如果没满,就输入e
}
template<class T,int MAXSIZE>
T Stack<T,MAXSIZE>::pop()
{
    if(empty())//如果空则返回0
    {cout<<"栈已空,不能再弹出元素!"<<endl;return 0;}
    return elem[top--];//未空则将元素返回
}

int main()
{
    Stack<int,10> iStack;
    Stack<char,10> cStack;
    iStack.setEmpty();//置空
    cStack.setEmpty();//置空
    // cout<<"..........intStack....\n";
    int i;
    // for(i=1;i<11;i++)
    // cout<<"\n\n...charStack...\n";
    cStack.push('A');
    cStack.push('B');
    cStack.push('C');
    cStack.push('D');
    cStack.push('S');
    cStack.push('A');
    cStack.push('G');
    cStack.push('B');
    cStack.push('K');
    for(i=1;i<10;i++)cout<<cStack.pop()<<"\t";
    cout<<endl;
    return 0;
}

