#include <iostream>
#include <string>
using namespace std;
class Point
{
    protected:
    float x,y;
    public:
    Point(float x=0,float y=0);
    void setPoint(float,float);
    float getX()const{return x;}
    float gexY()const{return y;}
    friend ostream& operator<<(ostream &,const Point &);
};
Point::Point(float a,float b)
{
    x=a;y=b;
}
void Point::setPoint(float a,float b)
{
    x=a;y=b;
}
ostream& operator<<(ostream &out,const Point &p)
{
    out<<"["<<p.x<<","<<p.y<<"]"<<endl;
    return out;
}
// int main()
// {
//     Point p(3.5,6.4);
//     cout<<"x:"<<p.getX()<<",y:"<<p.sexY()<<endl;
//     p.setPoint(8.5,6.8);
//     cout<<"x:"<<p.getX()<<",y:"<<p.sexY()<<endl;
//     return 0;
// }
class Circle:public Point
{
    public:
    Circle(float x=0,float y=0,float r=0);//圆的构造函数
    void setRadius(float);
    float getradius()const;
    float area()const;
    friend ostream& operator<<(ostream &out,Circle &c);
    private:
    float radius;
};
Circle::Circle(float a,float b,float r)
:Point(a,b){radius=r;}
void Circle::setRadius(float r)
{
    radius=r;
}
float Circle::getradius()const//声明之后定义也要写const
{return radius;}
float Circle::area()const
{
    return 3.14159*radius*radius;
}
ostream& operator<<(ostream &out,Circle &c)
{
    out<<"Center= ["<<c.x<<","<<c.y<<"]"<<endl;
    out<<"r="<<c.radius<<endl;
    out<<"area="<<c.area()<<endl;//直接调用面积函数
    return out;
}
// int main()
// {
//     Circle c(3.5,6.4,5.2);
//     cout<<"original circle:\nx="<<c.getX()<<",y="<<c.gexY()<<endl;
//     cout<<"radius="<<c.getradius()<<",area="<<c.area()<<endl;
//     c.setRadius(7.5);
//     c.setPoint(5,5);
//     cout<<"new circle:"<<endl;
//     cout<<c;
//     Point &pref=c;//
//     cout<<"pref:"<<pref<<endl;//输出的不是圆的信息
//     return 0;
// }
class Cylinder:public Circle
{
    public:
    Cylinder(float x=0,float y=0,float r=0,float h=0);
    void setHeight(float);
    float getHeight()const;
    float area()const;
    float volume()const;
    friend ostream& operator<<(ostream &out ,Cylinder &c);
    protected:
    float height;
};
Cylinder::Cylinder(float a,float b,float r,float h)
:Circle(a,b,r){height=h;}
void Cylinder::setHeight(float h)
{
    height=h;
}
float Cylinder::getHeight()const
{return height;}
float Cylinder::area()const
{
    return 2*Circle::area()+2*3.14159*Circle::getradius()*height;
}
float Cylinder::volume()const
{
    return height*Circle::area();
}
ostream & operator<<(ostream &out,Cylinder &c)
{
    out<<"Center=["<<c.getX()<<","<<c.gexY()<<"]"<<endl;
    out<<"radius="<<c.getradius()<<",area="<<c.area()<<endl;
    out<<"volume="<<c.volume()<<endl;
    return out;
}
int main()
{
    Cylinder cy1(3.5,6.4,5.2,10);
    cout<<"Center=["<<cy1.getX()<<","<<cy1.gexY()<<"]"<<endl;
    cout<<"radius="<<cy1.getradius()<<",area="<<cy1.area()<<endl;
    cout<<"volume="<<cy1.volume()<<endl;
    cy1.setHeight(15);
    cy1.setRadius(7.5);
    cy1.setPoint(5,5);
    cout<<"\nnew cylinder :\n";
    cout<<cy1<<endl;
    Point &p=cy1;
    cout<<"\np as a point:"<<p;
    Circle &c=cy1;
    cout<<"\nc ias a point:"<<c;
    return 0;
}
