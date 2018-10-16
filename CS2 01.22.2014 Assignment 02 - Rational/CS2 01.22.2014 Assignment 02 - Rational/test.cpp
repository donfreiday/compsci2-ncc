// Donald J Freiday
// CS2 : Assignment 2 : Rational Class
// test.cpp : Test the rational class

#include <iostream>
#include <fstream>
#include "rational.h"

using namespace std;

int main()
{
	ofstream fout;
	fout.open("output.txt", ios_base::out);
	if (fout.fail())
		return -1;

	fout << "Donald J Freiday\nCS2 : Assignment 2 : Rational Class\n\n";

	rational r1;
	fout << "Default rational r1: " << r1 << endl;

	cout << "\nEnter a new value for r1 in the form x/y: ";
	cin >> r1;
	fout << "User entered new value for r1 via cin << r1: " << r1 << endl;

	fout << "\nr1.numerator() : " << r1.numerator() << endl
		<< "r1.denominator(): " << r1.denominator() << endl;

	// rational r2(1, 0); // assert(denominator != 0) in constructor method;

	rational r2(1, 4);
	fout << "\nrational r2(1,4): " << r2 << endl;

	rational r3(r1);
	fout << "\nrational r3(r1): " << r3;

	rational r4 = r3;
	fout << "\nrational r4 = r3 : " << r4 << endl;
	
	fout << "\nr1 + r2 : " << r1 << " + " << r2 << " = " << r1 + r2 << endl;
	fout << "r1 - r2 : " << r1 << " - " << r2 << " = " << r1 - r2 << endl;
	fout << "r1 * r2 : " << r1 << " * " << r2 << " = " << r1 * r2 << endl;
	fout << "r1 / r2 : " << r1 << " / " << r2 << " = " << r1 / r2 << endl;

	rational r5(0, 1);
	fout << "\nrational r5 : " << r5 << endl;
	fout << "r5 + r1 : " << r5 << " + " << r1 << " = " << r5 + r1 << endl;
	fout << "r5 - r1 : " << r5 << " - " << r1 << " = " << r5 - r1 << endl;
	fout << "r5 * r1 : " << r5 << " * " << r1 << " = " << r5 * r1 << endl;
	fout << "r5 / r1 : " << r5 << " / " << r1 << " = " << r5 / r1 << endl;

	// fout << "r1 / r5 : " << r1 << " / " << r5 << " = " << r1 / r5 << endl; // assert for divide by 0

	fout.close();
}