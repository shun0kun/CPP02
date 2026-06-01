#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed const &other );
		Fixed	&operator=( Fixed const &other );
		~Fixed();
		int		getRawBits() const;
		void	setRawBits( int const raw );

	private:
		int					rawBits_;
		static int const	fractionalBits_ = 8;
};

#endif
