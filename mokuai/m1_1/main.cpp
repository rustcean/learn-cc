#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main()
{
    Point o = Point(0, 0);
	Circle c1 = Circle(o, 5);
	Point p1(3, 4);
	bool b = c1.IsInCircle(p1);
	cout << b << endl;
	o.Print();
	c1.Print();
}