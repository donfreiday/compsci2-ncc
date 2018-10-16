/**********************************************************************************************
Donald J Freiday
CS2 : Assignment 2 : Rational Class
***********************************************************************************************/

#include "math.h"
#include "gcd.h"

// LCM algorithm taken from wikipedia
// http://en.wikipedia.org/wiki/Least_common_multiple#Reduction_by_the_greatest_common_divisor
//
//                 | a * b |
// lcm(a, b) =  --------------
//                 gcd(a, b)
//
int lcm(int x, int y)
{
	if (x == 0 && y == 0) // prevent divide by zero crash
		return 0;
	return (abs(x*y) / gcd(x, y));
}

