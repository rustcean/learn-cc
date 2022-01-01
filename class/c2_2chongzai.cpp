#include <iostream>
using namespace std;
class Box
{
    public:
    Box(int h=10,int w=10,int l=10);
    int volume();
    private:
    int height;
    int width;
    int length;
};
Box::Box(int h,int w,int l)
{
    height=h;
    width=w;
    length=l;
}
//Box::Box(int h,int w,int l):height(h),width(w),length(l){}
int Box::volume()
{
    return height*width*length;
}
int main()
{
    //可以一些用默认值
    Box b1;cout<<b1.volume()<<endl;
    Box b2(15);
    cout<<b2.volume()<<endl;
    Box b3(15,30);
    cout<<b3.volume()<<endl;
    Box b4(15,30,20);
    cout<<b4.volume()<<endl;
    return 0;
}