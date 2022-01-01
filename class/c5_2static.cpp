#include <iostream>
using namespace std;
class Box
{
    public:
    Box(int ,int);
    int volume();
    static int height;
    int width;
    int length; 
};
Box::Box(int w,int len)
{
width=w;
length=len;
}
int Box::volume()
{
    return (height*width*length);
}
int Box::height=10;//一定要赋值,否则后面没法算

int main()
{
    Box a(15,20),b(20,30);
    cout<<a.height<<endl;
    cout<<b.height<<endl;
    cout<<Box::height<<endl;//可以通过类名引用静态数据成员height
    cout<<a.volume()<<endl;
    //cout<<height<<endl;不行
    return 0;
}