#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point( Point const &other );
		Point( int const x, int const y );
		Point( float const x, float const y );
		Point( Fixed const &x, Fixed const &y );
		Point	&operator=( Point const &other );
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		Fixed const	x_;
		Fixed const	y_;
};

Point	operator+( Point const &a, Point const &b );
Point	operator-( Point const &a, Point const &b );
Fixed	operator^( Point const &a, Point const &b );

#endif
