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

float Point::magnitude()
{
	return this->x_ * this->x_ + this->y_ * this->y_;
}

Point Point::normalize()
{

	return Point(this->x_ / this->magnitude(), this->y_ / this->magnitude());
}

Point Point::barycentre(std::vector<Point> listPoint)
{
	int size = listPoint.size();
	Point baryWhite;
	for (int i = 0; i < size; i++)
		baryWhite += listPoint[i];
	baryWhite /= size;
	return baryWhite;
}

Point::~Point()
{
}
