#include <iostream>
using namespace std;
class Shape
{
    public:
    //没写构造函数,因为抽象基类不能创造对象,不需要构造函数
    virtual float area()const {return 0.0;}
    virtual float volume()const{return 0.0;}
    virtual void shapeName()const=0;//纯虚函数
};
class Point:public Shape
{
    public:
    Point(float =0,float=0);
    void setPoint(float,float);
    float getX()const {return x;}
    float getY()const{return y;}
    virtual void shapeName()const{cout<<"Point:";}
    friend ostream&operator<<(ostream&,const Point &);
    protected:
    float x,y;
};
//Point类的函数定义
Point::Point(float a,float b){x=a;y=b;}
void Point::setPoint(float a,float b){x=a;y=b;}
ostream & operator<<(ostream &out,const Point &p)
{
    out<<"["<<p.x<<","<<p.y<<"]";
    return out;
}
//circle类的声明
class Circle:public Point
{
    public:
    Circle(float x=0,float y=0,float r=0);
    void setRadius(float);
    float getRadius()const;
    virtual float area()const;
    virtual void shapeName()const {cout<<"Circle";}
    friend ostream&operator<<(ostream &,const Circle &);
    protected :
    float radius;
};
//Circle类函数的定义
Circle::Circle(float a,float b,float r)
:Point(a,b),radius(r){}
void Circle::setRadius(float r){radius=r;}
float Circle::getRadius()const{return radius;}
float Circle::area()const{return radius*radius*3.14159;}
ostream & operator<<(ostream &out,const Circle &c)
{
    out<<"["<<c.x<<","<<c.y<<"],r="<<c.radius;
    return out;
}
//Cylinder的声明
class Cylinder:public Circle
{
    public:
    Cylinder(float x=0,float y=0,float r=0,float h=0);
    void setHeight(float);
    virtual float area()const;
    virtual float volume()const;
    virtual void shapeName()const{cout<<"Cylinder";}
    friend ostream&operator<<(ostream&,const Cylinder&);
    protected:
    float height;
};
//Cylinder的函数定义
Cylinder::Cylinder(float a,float b,float r,float h)
:Circle(a,b,r),height(h){}
void Cylinder::setHeight(float h)
{height=h;}
float Cylinder::area()const
{return 2*3.14159*radius*radius+2*3.14159*radius*height;}
float Cylinder::volume()const
{return 3.14159*radius*radius*height;}
ostream &operator<<(ostream&out,const Cylinder &c)
{
    out<<"["<<c.x<<","<<c.y<<"],r="<<c.radius<<",height="<<c.height;
    return out;
}
//主函数实现
int main()
{
    Point p(3.2,4.5);
    Circle ci(2.4,1.2,5.6);
    Cylinder cy(3.5,6.4,5.2,10.5);
    p.shapeName();
    cout<<p<<endl;
    ci.shapeName();
    cout<<ci<<endl;
    cy.shapeName();
    cout<<cy<<endl;
    cout<<"\n\n";
    Shape *pt;
    pt=&p;
    pt->shapeName();
    cout<<"x="<<p.getX()<<",y="<<p.getY()<<"\narea="<<pt->area()
    <<"\nvolume="<<pt->volume()<<"\n\n";
    
    pt=&ci;
    pt->shapeName();
    cout<<"x="<<ci.getX()<<",y="<<ci.getY()<<"\narea="<<pt->area()
    <<"\nvolume="<<pt->volume()<<"\n\n";

    pt=&cy;
    cout<<"x="<<cy.getX()<<",y="<<cy.getY()<<"\narea="<<pt->area()
    <<"\nvolume="<<pt->volume()<<"\n\n";
    return 0;
}