#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawBits_( 0 ) {}

Fixed::Fixed( Fixed const &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=( Fixed const &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &other )
		rawBits_ = other.rawBits_;
	return *this;
}

Fixed::Fixed( int const n )
{
	rawBits_ = n << fractionalBits_;
}

// Understand this completely.
Fixed::Fixed( float const n )
{
	rawBits_ = static_cast<int>( roundf( n * ( 1 << fractionalBits_ ) ) );
}

// Overflow can be treated as UB, but it's worth understanding how it behaves.


float	Fixed::toFloat() const
{

}

int	Fixed::toInt() const
{
	return rawBits_ / ( 1 << fractionalBits_ );
}
