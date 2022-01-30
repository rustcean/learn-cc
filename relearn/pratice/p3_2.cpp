
#include <iostream>
using namespace std;
//静态常量
const float PI=3.14159;
const float Fenceprice=35;//栅栏单价
const float Ailseprice=20;//过道单价

//类声明
class Circle
{
    float radius;
    public:
    Circle(float r):radius(r){}
    float Circumference()const;//周长
    float Area()const;//面积
};
float Circle::Circumference()const
{return 2*PI*radius;}
float Circle::Area()const
{return PI*radius*radius;}

//主函数
int main()
{
    float radius;
    float Fencecost=0,Ailsecost=0;
    //输入半径
    cout<<"Enter the radius of the pool:";
    cin>>radius;
    Circle pool(radius);//内圆
    Circle poolRim(radius+3);//外圆
    Fencecost=poolRim.Circumference()*Fenceprice;
    cout<<"Fencing cost is $"<<Fencecost<<endl;//栅栏造价
    Ailsecost=(poolRim.Area()-pool.Area())*Ailseprice;
    cout<<"Ailse cost is $"<<Ailsecost<<endl;//过道造价
    return 0;
}