//c++ 11所谓的新的线程库
#include <iostream>
#include <thread>
//没看懂的操作
std::thread::id main_thread_id=std::this_thread::get_id();

void hello()
{
    std::cout<<"Hello Concurrent World"<<std::endl;
    if(main_thread_id==std::this_thread::get_id())
        std::cout<<"This is the main thread."<<std::endl;
    else
        std::cout<<"This is not the main thread"<<std::endl;
}

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout<<"pause of "<<n<<"sconds ended"<<std::endl;
}

int main()
{
    std::thread t(hello);
    std::cout<<t.hardware_concurrency()<<std::endl;//可以并发执行多少个(不准确)
    std::cout<<"native_handle"<<t.native_handle()<<std::endl;//可以并发执行多少个(不准确)
    t.join();
    std::thread a(hello);
    a.detach();//这是啥函数?
    std::thread threads[5];//默认构造线程
    std::cout<<"Spawing 5 threads..."<<std::endl;
    for(int i=0;i<5;i++)
        threads[i]=std::thread(pause_thread,i+1);//move-assign threads
    std::cout<<"Done spawning hreads.Now waiting for them to join:"<<std::endl;
    for(auto &thread:threads)//没看懂
        thread.join();
    std::cout<<"All threads joined!"<<std::endl;
}