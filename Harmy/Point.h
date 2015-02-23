#pragma once
#include <vector>

class Point
{
public:
	Point();
	Point(int x, int y);
	int x_get() { return this->x_; }
	int y_get() { return this->y_; }
	void x_set(int value) { this->x_ = value; }
	void y_set(int value) { this->y_ = value; }
	int Distance(Point otherPoint);
	~Point();
private:
	int x_;
	int y_;
};

