#ifndef POINT_H
#define POINT_H
class Point
{
public:
	int GetX();
	int GetY();
	Point(int x, int y);
	Point();
	void Print();
private:
	int x;
	int y;
};
#endif


/*
#pragma once  --表示只读一次 --跟上面应该是一样的效果
*/