#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const &other );
		Fixed	&operator=( Fixed const &other );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed();

		int		getRawBits() const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int		toInt() const;

	private:
		int					rawBits_;
		static int const	fractionalBits_ = 8;
};

std::ostream	&operator<<( std::ostream &os, Fixed const &rhs );

#endif
