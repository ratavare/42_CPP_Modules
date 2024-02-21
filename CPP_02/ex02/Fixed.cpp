#include "Fixed.hpp"

Fixed::Fixed() {
	this->fixedValue = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy) {
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
	this->fixedValue = value << numberBits;
}

Fixed::Fixed(const float value) {
	this->fixedValue = roundf(value * (1 << numberBits));
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(this->fixedValue) / (1 << numberBits));
}

int	Fixed::toInt( void ) const {
	return (fixedValue >> numberBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed& fixed) {
	return (this->fixedValue > fixed.fixedValue);
}

bool Fixed::operator>=(const Fixed& fixed) {
	return (this->fixedValue >= fixed.fixedValue);
}

bool Fixed::operator<(const Fixed& fixed) {
	return (this->fixedValue < fixed.fixedValue);
}

bool Fixed::operator<=(const Fixed& fixed) {
	return (this->fixedValue <= fixed.fixedValue);
}

bool Fixed::operator==(const Fixed& fixed) {
	return (this->fixedValue == fixed.fixedValue);
}

bool Fixed::operator!=(const Fixed& fixed) {
	return (this->fixedValue != fixed.fixedValue);
}

Fixed Fixed::operator+(const Fixed &fixed) {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) {
	return (Fixed(this->toFloat() * fixed.toFloat()));\
}

Fixed Fixed::operator/(const Fixed& fixed) {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++() {
	this->fixedValue++;
	return (*this);
}

Fixed& Fixed::operator--() {
	this->fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixedValue--;
	return(tmp);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->fixedValue++;
	return(tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a.toFloat() < b.toFloat()) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a.toFloat() < b.toFloat()) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a.toFloat() > b.toFloat()) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a.toFloat() > b.toFloat()) ? a : b);
}
