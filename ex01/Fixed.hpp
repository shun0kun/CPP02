#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const &other );
		Fixed	&operator=( Fixed const &other );
		Fixed( int const raw );
		Fixed( float const raw );
		~Fixed();

		int		getRawBits() const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int		toInt() const;


	private:
		int					rawBits_;
		static int const	fractionalBits_ = 8;
};

#endif
