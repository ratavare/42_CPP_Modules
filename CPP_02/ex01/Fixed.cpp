#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	return (this->fixedValue);
}

void Fixed::setRawBits( int const raw ) {
	this->fixedValue = raw;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = value << numberBits;
}

Fixed::Fixed(const float value) {
	std::cout <<"Float constructor called" << std::endl;
	this->fixedValue = roundf(value * (1 << numberBits));
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(fixedValue) / (1 << numberBits));
}

int	Fixed::toInt( void ) const {
	return (fixedValue >> numberBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}