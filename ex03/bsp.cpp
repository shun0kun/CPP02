#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed c1 = ( b - a ) ^ ( point - a );
	Fixed c2 = ( c - b ) ^ ( point - b );
	Fixed c3 = ( a - c ) ^ ( point - c);

	return ( c1 > 0 && c2 > 0 && c3 > 0 ) || ( c1 < 0 && c2 < 0 && c3 < 0 );
}
