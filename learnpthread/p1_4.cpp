//链接和分离线程
//pthread_join子程序阻止调用程序,直到指定的thread线程结束为止
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;
const int NUM_THREADS=5;
void *wait(void *t)
{
    int i;
    long int tid;
    tid=(long)t;
    sleep(1);
    cout<<"Sleeping in thread"<<endl;
    cout<<"Thread with id:"<<tid<<"  ...exiting"<<endl;
    pthread_exit(NULL);
}

int main()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t  attr;
    void *status;
    //初始化并设置线程为可链接的(joinable)
    pthread_attr_init(&attr);//使用需要先初始化
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    //添加性质为joinable--此时会等待线程的完成
    for(i=0;i<NUM_THREADS;i++)
    {
        cout<<"main():creating thread,"<<i<<endl;
        rc=pthread_create(&threads[i],NULL,wait,(void *)&i);
        if(rc)
        {
            cout<<"Error : unable to create thread,4"<<rc<<endl;
            exit(-1);
        }
    }
    //删除属性,并等待其他线程
    pthread_attr_destroy(&attr);
    
    for(i=0;i<NUM_THREADS;i++)
    {
        rc=pthread_join(threads[i],&status);
        if(rc)
        {
            cout<<"Error:unabe to join,5"<<rc<<endl;
            exit(-1);
        }
        cout<<"Main:completed thread id:"<<i;
        cout<<" exiting with status :"<<status<<endl;
    }
    cout<<"Main:progrem exiting."<<endl;
    pthread_exit(NULL);
}
//有看到如果设置为 PTHREAD_CREATE_JOINABLE，就继续用 
//pthread_join() 来等待和释放资源，否则会内存泄露。
