#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedPointvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	int temp = i;
	int count = this->_bits;
	while (count > 0)
	{
		temp *= 2;
		count--;
	}
	this->_fixedPointvalue = temp;
}

Fixed::Fixed(const float f)
{
	float tmp = f;
	std::cout << "Float constructor called" << std::endl;
	int i = this->_bits;
	while (i > 0)
	{
		tmp *= 2;
		i--;
	}
	this->_fixedPointvalue = roundf(tmp);
}

Fixed::Fixed(const Fixed &objet) : _fixedPointvalue(objet._fixedPointvalue)
{
	std::cout << "Copy constructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &objet) //deja existant obj
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointvalue = objet._fixedPointvalue;
	return (*this);
}

std::ostream &operator<<(std::ostream &sortie, const Fixed &objet)
{
	sortie << objet.toFloat();
	return (sortie);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointvalue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointvalue = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	float tmp = (float)this->_fixedPointvalue;
	int i = this->_bits;
	while (i > 0)
	{
		tmp /= 2;
		i--;
	}
	return tmp;
}

int Fixed::toInt(void) const
{
	int tmp = this->_fixedPointvalue;
	int i = this->_bits;
	while (i > 0)
	{
		tmp /= 2;
		i--;
	}
	return tmp;
}
