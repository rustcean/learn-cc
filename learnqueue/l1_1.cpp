//队列
//编译:g++ l1_1.cpp -o l11 无需其他参数
//只能操作頭跟尾, 不能取得中間的值(根據FIFO特性) 
//queue 是一層容器的包裝, 背後是用 deque 實現的, 並且只提供特定的函數接口

/*
相当于emplace直接把原料拿进家，造了一个。
而push是造好了之后，再复制到自己家里，多了复制这一步。
所以emplace相对于push，使用第三种方法会更节省内存
*/

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.empty()<<endl;//0
    cout<<q.size()<<endl;
    // cout<<q.swap()<<endl;
    int a=q.front();//copy
    int &b=q.front();//reference

    cout<<q.front()<<" "<<&q.front()<<endl;
    cout<<b<<" "<<&b<<endl;
    cout<<a<<" "<<&a<<endl;

    int size =q.size();
    for(int i=0;i<size;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<q.empty()<<endl;//1

    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}