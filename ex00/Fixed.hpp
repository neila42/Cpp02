#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &objet);
	Fixed &operator=(const Fixed &objet);
	~Fixed(void);
		
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedPointvalue;
	static const int _bits = 8;
};

#endif
