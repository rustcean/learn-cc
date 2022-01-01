#include <iostream>
using namespace std;
class Time
{
    public:
    Time(int ,int,int );
    const int hour;
    int minute;
    int sec;
    void put_time()const;
    //将函数命名为const型时,上面就是格式
};
Time::Time(int h,int m,int s):hour(h)
//当对象成员是const型的时候,只能用表格形式来初始化--常数据成员不能被赋值
{
    minute=m;
    sec=s;
}
void Time::put_time()const
{
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
int main()
{
    Time const t1(10,13,56);
    //使用const对象时,函数必须是const型,否则不可引用
    t1.put_time();
    Time const *p1=&t1;
    /*Time *const p1=&t1;出错,这样类型不行*/
    (*p1).put_time();
    //(*p1)->put_time();出错
    //*p1.put_time();
    Time t2(11,12,13);
    Time *const p2=&t2;
    (*p2).put_time();
    //(*p2)->put_time();出错
    void fun(const Time *);
    fun(&t2);
    return 0;
}
void fun(const Time *p)
{
    cout<<p->hour<<endl;
//可以引用类里面的数据,有点奇怪
}