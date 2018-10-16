// Donald J Freiday
// CS2 : Assignment 2 : Rational Class
// rational.cpp : Implementation of rational class

#include <assert.h>
#include <iostream>
#include "gcd.h"
#include "lcm.h"
#include "rational.h"

rational::rational()
{
	myNumerator = 1;
	myDenominator = 1;
}

rational::rational(int numerator, int denominator)
{
	assert(denominator != 0);
	myNumerator = numerator;
	myDenominator = denominator;
	reduce();
}

rational::rational(const rational &r)
{
	myNumerator = r.myNumerator;
	myDenominator = r.myDenominator;
}

int rational::numerator() const
{
	return myNumerator;
}

int rational::denominator() const
{
	return myDenominator;
}

const rational& rational::operator= (const rational &rhs)
{
	if (this != &rhs)
	{
		myNumerator = rhs.numerator();
		myDenominator = rhs.denominator();
	}
	return *this;
}

void rational::reduce()
{
	int commonDivisor = gcd(myNumerator, myDenominator);
	myNumerator /= commonDivisor;
	myDenominator /= commonDivisor;
}

rational operator + (const rational &lhs, const rational &rhs)
{
	int numerator = lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator();
	int denominator = lhs.denominator() * rhs.denominator();
	rational sum(numerator, denominator);
	return sum;
}

rational operator - (const rational &lhs, const rational &rhs)
{
	int numerator = lhs.numerator()*rhs.denominator() - lhs.denominator()*rhs.numerator();
	int denominator = lhs.denominator()*rhs.denominator();
	rational difference(numerator, denominator);
	return difference;
}

rational operator * (const rational &lhs, const rational &rhs)
{
	int numerator = lhs.numerator() * rhs.numerator();
	int denominator = lhs.denominator() * rhs.denominator();
	rational product(numerator, denominator);
	return product;
}

rational operator / (const rational &lhs, const rational &rhs)
{
	assert(rhs.numerator() != 0); // divide by zero. could handle this in a more friendly way
	int numerator = lhs.numerator()*rhs.denominator();
	int denominator = lhs.denominator()*rhs.numerator();
	rational quotient(numerator, denominator);
	return quotient;
}

bool operator == (const rational &lhs, const rational &rhs)
{
	if (lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator())
		return true;
	return false;
}

// IO
ostream &operator << (ostream &os, const rational &r)
{
	os << r.numerator() << "/" << r.denominator();
	return os;
}

istream &operator >> (istream &is, rational &r)
{
	char divisionSymbol;
	int numerator = 0, denominator = 0;

	is >> numerator >> divisionSymbol >> denominator;
	assert(divisionSymbol == '/');
	assert(denominator != 0);
	rational number(numerator, denominator);
	r = number;
	return is;
}
