#include "Point.hpp"

Point::Point() : x_( 0 ), y_( 0 )
{
}

Point::Point( Point const &other ) : x_( other.x_ ), y_( other.y_ )
{
}

Point::Point( int x, int y ) : x_( x ), y_( y )
{
}

Point::Point( float x, float y ) : x_( x ), y_( y )
{
}

Point::Point( Fixed const &x, Fixed const &y ) : x_( x ), y_( y )
{
}

Point	&Point::operator=( Point const &other )
{
	( void )other;
	return *this;
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return x_;
} 

Fixed	Point::getY() const
{
	return y_;
}

Point	operator+( Point const &a, Point const &b )
{
	return Point( a.getX() + b.getX(), a.getY() + b.getY() );
}

Point	operator-( Point const &a, Point const &b )
{
	return Point( a.getX() - b.getX(), a.getY() - b.getY() );
}

Fixed	operator^( Point const &a, Point const &b )
{
	return a.getX() * b.getY() - a.getY() * b.getX();
}
