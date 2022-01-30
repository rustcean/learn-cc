/**静态成员函数
 * 类外代码可以使用类名和作用域操作符来跳用静态成员函数
 * 静态成员函数只能引用该类的静态成员数据或函数
 * 静态数据成员必须在类外进行定义和初始化
**/
#include <iostream>
using namespace std;
class Point
{
    public :
    Point(int xx=0,int yy=0){X=xx;Y=yy;countP++;}
    Point(Point &p);
    int getx()const{return X;}
    int gety()const{return Y;}
    void getc()const{cout<<"object id="<<countP<<endl;}
    private:
    int X,Y;
    static int countP;
};
Point::Point(Point &p)
{
    X=p.X;
    Y=p.Y;
    countP++;
}
//在类外对static数据进行赋值
int Point::countP=0;
int main()
{
    Point A(4,5);
    cout<<"Point A:"<<A.getx()<<","<<A.gety()<<" ";
    A.getc();
    Point B(A);
    cout<<"Point B :"<<B.getx()<<","<<B.gety()<<" ";
    B.getc();
    return 0;
}

