#include "Circle.h"
#include "Point.h"
#include <iostream>
using namespace std;
double Circle::GetR(double r)  //要写出作用域Circle::
{
	m_r = r;
	return m_r;
}
 
double Circle::GetS()
{
	m_s = 3.14*m_r*m_r;
	return m_s;
}
 
double Circle::GetC()
{
	m_c = 2 * 3.14*m_r;
	return m_c;
}
 
Point Circle::GetO()
{
	return o;
}
 
bool Circle::IsInCircle(Point p)
{
	if (((p.GetX() - o.GetX())*(p.GetX() - o.GetX()) + (p.GetY() - o.GetY())*(p.GetY() - o.GetY())) <= m_r*m_r)
	{
		return true;
	}
	else
	{
		return false;
	};
}
 
Circle::Circle(Point o1, double r1)
{
	o = o1;
	m_r = r1;
}
Circle::Circle()
{}

void Circle::Print()
{
	cout<<"Circle类: "<<endl;
	cout<<"调用<iostream>库，使用stdnamspace"<<endl;
}