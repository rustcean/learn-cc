//注意:使用g++编译pthread库需要加上 -pthread
//pthread_create (thread, attr, start_routine, arg) 
// arg 必须通过把引用作为指针强制转换为 void 类型进行传递或者为NULL
#include <iostream>
// #include <cstdlib>
#include <pthread.h>
using namespace std;

void *PrintHello(void *threadid)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid=*((int *)threadid);
    cout<<"Hello 线程ID,"<<tid<<endl;
    pthread_exit(NULL);//为何在这里就把线程杀死
}
int main()
{
    pthread_t threads[5];
    int indexes[5];//数组保存i的值
    int rc;//用来判断是否成功建立线程
    for(int i=0;i<5;i++)
    {
        cout<<"main():创建线程,"<<i<<endl;
        indexes[i]=i;//保存i的值
        //传入的时候必须强制类型转换为void*类型,即无类型指针
        rc=pthread_create(&threads[i],NULL,
                PrintHello,(void *)&(indexes[i]));
        if(rc)//不为0时就是创建失败
        {
            cout<<"Error:无法创建线程,"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);//结束线程,保证进程结束前,线程一定已经结束
    return 0;
}