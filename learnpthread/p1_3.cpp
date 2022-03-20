#include <iostream>
#include <pthread.h>
using namespace std;

struct thread_data//通过结构体可以传递多个参数
{
    int thread_id;
    char *message;
};
const int NUM_THREADS=5;

void *PrintHello(void *threadarg)
{
    struct thread_data *my_data;
    my_data=(struct thread_data *) threadarg;
    cout<<"Thread_id:"<<my_data->thread_id;
    cout<<"Mssage: "<<my_data->message<<endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];//创建多个线程id,
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;
    for(i=0;i<NUM_THREADS;i++)
    {
        cout<<"man():creating thread,"<<i<<endl;
        td[i].thread_id=i;
        td[i].message=(char *)"this is message";
        rc=pthread_create(&threads[i],NULL,
                PrintHello,(void *)&td[i]);
        if(rc)
        {
            cout<<"Error:unable to creat tread,"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}