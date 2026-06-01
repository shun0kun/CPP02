#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
	const int n_tests = 1;
	Point a[n_tests] = {Point(0, 0)};
	Point b[n_tests] = {Point(2, 0)};
	Point c[n_tests] = {Point(1, 2)};
	Point point[n_tests] = {Point(1, 1)};
	bool expected[n_tests] = {true};

	std::cout << "expected, actual" << std::endl;
	for ( int i = 0; i < n_tests; i++ )
		std::cout << expected[i] << ", " << bsp( a[i], b[i], c[i], point[i] ) << std::endl;
	
	return 0;
}
