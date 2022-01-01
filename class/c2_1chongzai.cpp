#include <iostream>
using namespace std;
class Box
{
    public :
    Box();
    Box(int h,int w,int l):height(h),width(w),length(l){}
    int volume();
    private:
    int height;
    int width;
    int length;
};
Box::Box()
{
    height=10;
    width=10;
    length=10;
}
int Box::volume()
{
    return height*width*length;
}
int main()
{
    Box b1;
    cout<<b1.volume()<<endl;//1000
    Box b2(15,30,25);
    cout<<b2.volume()<<endl;
    return 0;
}