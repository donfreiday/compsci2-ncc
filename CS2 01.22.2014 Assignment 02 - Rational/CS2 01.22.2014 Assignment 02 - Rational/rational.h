// Donald J Freiday
// CS2 : Assignment 2 : Rational Class
// rational.h : Header for rational class

#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>

using namespace std;

class rational
{
public:
	rational();
	rational(int numerator, int denominator);
	rational(const rational &r);

	int numerator() const;
	int denominator() const;

	const rational &operator = (const rational &rhs);

private:
	int myNumerator, myDenominator;

	void reduce();
};

// The following free (non-member) funcitons operate on rational numbers

// Arithmetic

rational operator + (const rational &lhs, const rational &rhs);
rational operator - (const rational &lhs, const rational &rhs);
rational operator * (const rational &lhs, const rational &rhs);
rational operator / (const rational &lhs, const rational &rhs);
bool operator == (const rational &lhs, const rational &rhs);

// IO
ostream &operator << (ostream &os, const rational &r);
istream &operator >> (istream &is, rational &r);

#endif