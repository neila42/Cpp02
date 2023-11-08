#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedPointvalue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &objet) : _fixedPointvalue(objet._fixedPointvalue)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &objet) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointvalue = objet._fixedPointvalue;
	return (*this);
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
