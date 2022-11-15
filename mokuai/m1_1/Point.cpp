#include "Point.h"
#include <iostream>
using namespace std;
//构造函数
Point::Point(int x1, int y1)
{
	x = x1;
	y = y1;
}
Point::Point()
{}

//值获取函数
int Point::GetX()  
{return x;}
 
int Point::GetY()
{return y;}
 
void Point::Print()
{
	cout<<"Point类:"<<endl;
	cout<<"调用<iostream>库，使用stdnamspace"<<endl;
}

