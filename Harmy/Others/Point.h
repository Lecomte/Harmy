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
	float magnitude();
	Point normalize();
	void operator+=(Point p) { this->x_ += p.x_; this->y_ += p.y_; }
	void operator/=(float f) { this->x_ /= f; this->y_ /= f; }
	Point operator-(Point p) { return Point(this->x_ - p.x_, this->y_ - p.y_); }
	Point operator*(float f) { return Point(this->x_ * f, this->y_ * f); }
	Point barycentre(std::vector<Point> listPoint);
	~Point();
private:
	int x_;
	int y_;
};

