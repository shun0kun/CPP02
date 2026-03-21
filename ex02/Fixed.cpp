#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawBits_( 0 )
{
}

Fixed::Fixed( Fixed const &other )
{
	*this = other;
}

Fixed	&Fixed::operator=( Fixed const &other )
{
	rawBits_ = other.rawBits_;
	return *this;
}

Fixed::Fixed( int const raw )
{
	rawBits_ = raw << fractionalBits_;
}

Fixed::Fixed( float const raw )
{
	rawBits_ = static_cast<int>( roundf( raw * ( 1 << fractionalBits_ ) ) );
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return rawBits_;
}

int	Fixed::getFractionalBits()
{
	return fractionalBits_;
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

Fixed	&Fixed::operator++()
{
	++rawBits_;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;

	++rawBits_;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	--rawBits_;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;

	--rawBits_;
	return tmp;
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return a.rawBits_ < b.rawBits_ ? a : b;
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	return a.rawBits_ < b.rawBits_ ? a : b;
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return a.rawBits_ > b.rawBits_ ? a : b;
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	return a.rawBits_ > b.rawBits_ ? a : b;
}

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs )
{
	return os << rhs.toFloat();
}

bool	operator>( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() > rhs.getRawBits();
}

bool	operator<( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() < rhs.getRawBits();
}

bool	operator>=( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool	operator<=( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool	operator==( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool	operator!=( Fixed const &lhs, Fixed const &rhs )
{
	return lhs.getRawBits() != rhs.getRawBits();
}

Fixed	operator+( Fixed const &lhs, Fixed const &rhs )
{
	Fixed res;

	res.setRawBits( lhs.getRawBits() + rhs.getRawBits() );
	return res;
}

Fixed	operator-( Fixed const &lhs, Fixed const &rhs )
{
	Fixed res;

	res.setRawBits( lhs.getRawBits() - rhs.getRawBits() );
	return res;
}

Fixed	operator*( Fixed const &lhs, Fixed const &rhs )
{
	Fixed res;

	res.setRawBits( static_cast<int>( static_cast<long long>( lhs.getRawBits() ) * rhs.getRawBits() / (1 << Fixed::getFractionalBits()) ) );
	return res;
}

// 0除算を弾くのもあり。
Fixed	operator/( Fixed const &lhs, Fixed const &rhs )
{
	Fixed res;

	res.setRawBits( static_cast<int>( static_cast<long long>( lhs.getRawBits() ) * ( 1 << Fixed::getFractionalBits() ) / rhs.getRawBits() ) );
	return res;
}

