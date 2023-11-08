#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedPointvalue(0)
{}

Fixed::Fixed(const int i)
{
	int tmp = i;
	int count = this->_bits;
	while (count > 0)
	{
		tmp *= 2;
		count--;
	}
	this->_fixedPointvalue = tmp;
}

Fixed::Fixed(const float f)
{
	float tmp = f;
	int count = this->_bits;
	while (count > 0)
	{
		tmp *= 2;
		count--;
	}
	this->_fixedPointvalue = roundf(tmp);
}

Fixed::Fixed(const Fixed &t) : _fixedPointvalue(t._fixedPointvalue)
{}

Fixed::~Fixed(void)
{}

Fixed &Fixed::operator=(const Fixed &f) 
{
	this->_fixedPointvalue = f._fixedPointvalue;
	return (*this); // A = B = C	C envoie ref à B, B revoie ref à A
}

bool	Fixed::operator>(const Fixed &f) const // pour "comparer" des OBJETS
{
	return (this->toFloat() > f.toFloat());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->toFloat() < f.toFloat());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->toFloat() >= f.toFloat());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->toFloat() <= f.toFloat());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->toFloat() == f.toFloat());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->toFloat() != f.toFloat());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = (*this);
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = (*this);
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointvalue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointvalue = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	float tmp = this->_fixedPointvalue;
	int count = this->_bits;
	while (count > 0)
	{
		tmp /= 2;
		count--;
	}
	return tmp;
}

int Fixed::toInt(void) const
{
	int tmp = this->_fixedPointvalue;
	int count = this->_bits;
	while (count > 0)
	{
		tmp /= 2;
		count--;
	}
	return tmp;
}
