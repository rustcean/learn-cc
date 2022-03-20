#include <iostream>
#include <thread>//c++ 11添加了新的标准库
//调用对像:函数指针,函数对象,lambda表达式
using namespace std;

void foo(int z)
{
    for (int i=0;i<z;i++)
    {
        cout<<"线程使用函数指针作为可调用对象1"<<endl;
    }   
}

//可调用对象
class thread_obj
{
    public:
        void operator()(int x)
        {
            for(int i=0;i<x;i++)
            {
                cout<<"线程使用按数对象作为可跳用参数2"<<endl;
            }
        }
};

int main()
{
    cout<<"线程1,2,3"
    "独立运行"<<endl;

    //函数指针
    thread th1(foo,3);

    //函数对象
    thread th2(thread_obj(),3);

    //定义lambda表达式
    auto f=[](int x)
    {
        for(int i=0;i<x;i++)
        cout<<"线程使用lambda表达式做为可用参数3"<<endl;
    };

    //线程通过使用lambda表达式作为可用参数
    thread th3(f,3);

    //等待线程完成
    //等待线程t1完成
    th1.join();

    //等待线程 t2的完成
    th2.join();

    //等待线程 t3的完成
    th3.join();
    return 0;
}
//可见,是thread出一个量, 
//直接加对象(函数,类对象,lambda表达式)和参数--独立的一个线程
//用量.join()结束
