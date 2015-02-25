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

Point::Point(float x, float y)
{
	this->x_ = x;
	this->y_ = y;
}

float Point::Distance(Point otherPoint)
{
	Point vecteur = Point(otherPoint.x_get() - this->x_get(), otherPoint.y_get() - this->y_get());
	return std::sqrt(vecteur.magnitude());
	//return std::abs(this->x_get() - otherPoint.x_get()) + std::abs(this->y_get() - otherPoint.y_get());
}

float Point::magnitude()
{
	return this->x_ * this->x_ + this->y_ * this->y_;
}

Point Point::normalize()
{
	float distance = std::sqrt(this->magnitude());
	if (distance == 0.0f)
		return Point(0, 0);
	return Point(std::roundf((this->x_ / distance) * 100.0f) / 100.0f, std::roundf((this->y_ / distance) * 100.0f) / 100.0f);
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
