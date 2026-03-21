#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const &other );
		Fixed				&operator=( Fixed const &other );
		Fixed( int const raw );
		Fixed( float const raw );
		~Fixed();

		int					getRawBits() const;
		static int			getFractionalBits();
		void				setRawBits( int const raw );
		float				toFloat() const;
		int					toInt() const;
	
		Fixed				&operator++();
		Fixed				operator++( int );
		Fixed				&operator--();
		Fixed				operator--( int );

		static Fixed		&min( Fixed &a, Fixed &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );

	private:
		int					rawBits_;
		static int const	fractionalBits_ = 8;
};

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs );

bool			operator>( Fixed const &lhs, Fixed const &rhs );
bool			operator<( Fixed const &lhs, Fixed const &rhs );
bool			operator>=( Fixed const &lhs, Fixed const &rhs );
bool			operator<=( Fixed const &lhs, Fixed const &rhs );
bool			operator==( Fixed const &lhs, Fixed const &rhs );
bool			operator!=( Fixed const &lhs, Fixed const &rhs );

Fixed			operator+( Fixed const &lhs, Fixed const &rhs );
Fixed			operator-( Fixed const &lhs, Fixed const &rhs );
Fixed			operator*( Fixed const &lhs, Fixed const &rhs );
Fixed			operator/( Fixed const &lhs, Fixed const &rhs );



#endif
