#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed( const Fixed &other );
		Fixed	&operator=( const Fixed &other );
		~Fixed();
		int		getRawBits() const;
		void	setRawBits( int const raw );

	private:
		int					rawBits_;
		static int const	fractionalBits_ = 8;
};

#endif
