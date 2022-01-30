#include <iostream>
using namespace std;
class Apple
{
    private:
     int people[100];
    public:
    Apple(int i);
    const int applenum;
    void take(int num)const;
    int add(int num);
    int add(int num)const;
    int getCount()const;
};
Apple::Apple(int i):applenum(i){}
int Apple::add(int num)
{
    cout<<"no const"<<endl;
    take(num);
    return 0;
}
int Apple::add(int num)const
{
    cout<<"const"<<endl;
    take(num);
    return 0;
}
int Apple::getCount()const
{
    take(1);
    return applenum;
}
void Apple::take(int num)const
{
    cout<<"take "<<"func"<<num<<endl;
}

int main()
{
    Apple a(2);
    cout<<a.getCount()<<endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
