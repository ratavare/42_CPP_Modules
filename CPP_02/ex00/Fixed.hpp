#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int value;
	static const int numberBits = 8;

public:
	Fixed();
	Fixed(Fixed &copy);
	Fixed& operator=(const Fixed &copy);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif