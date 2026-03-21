#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawBits_( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

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

Fixed::Fixed( int const raw )
{
	std::cout << "Int constructor called" << std::endl;
	rawBits_ = raw << fractionalBits_;
}

Fixed::Fixed( float const raw )
{
	std::cout << "Float constructor called" << std::endl;
	rawBits_ = static_cast<int>( roundf( raw * ( 1 << fractionalBits_ ) ) );
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return rawBits_;
}

void	Fixed::setRawBits( int const raw )
{
	rawBits_ = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>( rawBits_ ) / ( 1 << fractionalBits_ );
}

int	Fixed::toInt() const
{
	return rawBits_ / ( 1 << fractionalBits_ );
}

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs )
{
	return os << rhs.toFloat();
}
