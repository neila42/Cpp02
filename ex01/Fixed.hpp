#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &objet);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed(void);
	Fixed &operator=(const Fixed &objet);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedPointvalue;
	static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &sortie, const Fixed &objet);

#endif
