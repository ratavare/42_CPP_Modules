#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int fixedValue;
	static const int numberBits = 8;

public:
	Fixed();
	Fixed(const int	value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed& operator=(const Fixed &copy);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed& fixed);
	bool operator>=(const Fixed& fixed);
	bool operator<(const Fixed& fixed);
	bool operator<=(const Fixed& fixed);
	bool operator==(const Fixed& fixed);
	bool operator!=(const Fixed& fixed);

	Fixed& operator+(const Fixed& fixed);
	Fixed& operator-(const Fixed& fixed);
	Fixed& operator*(const Fixed& fixed);
	Fixed& operator/(const Fixed& fixed);

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif