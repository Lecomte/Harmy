#include "Point.h"

Point::Point()
{
	this->x_ = 0;
	this->y_ = 0;
}

Point::Point(int x, int y)
{
	this->x_ = x;
	this->y_ = y;
}

int Point::Distance(Point otherPoint)
{
	return std::abs(this->x_get() - otherPoint.x_get()) + std::abs(this->y_get() - otherPoint.y_get());
}

Point::~Point()
{
}
