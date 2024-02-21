#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const float a, const float b) : x(a) , y(b) {}

Point::Point(const Point&copy) : x(copy.x) , y(copy.y) {}

Point& Point::operator=(const Point& copy) {
	(void)copy;
    return (*this);
}

Fixed Point::getX() const {
	return (x);
}

Fixed Point::getY() const {
	return (y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (os);
}