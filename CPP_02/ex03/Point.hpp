#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const float a, const float b);
	Point(const Point& copy);
	~Point();

	Point& operator=(const Point& copy);

	Fixed getX() const;
	Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif
