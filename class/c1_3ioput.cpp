#include <iostream>
using namespace std;
class Box
{
    public:
    Box(int h,int w,int l):height(h),width(w),length(l){}//初始化表省空间,可以直接写在定义时
    int volume();
    void show();
    private:
    int height;
    int width;
    int length;

};
// Box::Box(int h,int w,int l)
// {
//     height=h;
//     width=w;
//     length=l;
// }
int Box::volume()
{
    return (height*width*length);
}
void Box::show()
{
    cout<<"The volume of box is "<<volume()<<endl;
}
int main()
{
    Box b1(12,25,30);
    b1.show();
    Box b2(15,21,30);
    cout<<b2.volume()<<endl;
    Box b3=b2;//可以直接赋值,像变量
    cout<<b3.volume()<<endl;
    return 0;
}