#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h" //因为要用到Point类
#include <string>
class Circle
{
public:
 
	double GetR(double r);
	
	double GetS();
	
	double GetC();
	
	Point GetO();
	
	bool IsInCircle(Point p);
	
	Circle(Point o1, double r1);
 
	Circle();

	void Print();
 
private:
	double m_r;
	double m_s;
	double m_c;
	Point o;
	std::string name="";
};

#endif