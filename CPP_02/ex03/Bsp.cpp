#include "Bsp.hpp"

// Using the Area of a triangle in coordinate geometry formula: A = (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|

Fixed	getArea(Point const a, Point const b, Point const c) {
	Fixed A = Fixed(0.5f) * (a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - b.getY()));
	if (A < 0)
		A = A * -1;
	return (A);
}

// The point will be contained in the tringle if the sum of the areas of possible triangles
// using the given point are equivalent to the area of the original triangle.

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed abcArea = getArea(a, b, c);
	Fixed pabArea = getArea(point, a, b);
	Fixed pacArea = getArea(point, a, c);
	Fixed pbcArea = getArea(point, b, c);
	
	if (pabArea + pacArea + pbcArea != abcArea)
		return (false);
	return (true);
}