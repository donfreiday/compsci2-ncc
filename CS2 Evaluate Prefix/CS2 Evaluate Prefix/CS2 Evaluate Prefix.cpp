// CS2 Evaluate Prefix.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int endPre(string strExp, int first);
bool isPrefix(string strExp);
string evaluatePrefix(string strExp);

int main()
{
	string s;
	cout << "Enter a prefix expression:" << endl;
	cin >> s;
	cout << "\nThe prefix expression evaluates to: "<<evaluatePrefix(s)<<endl;

	return 0;
}

// Finds the end of a prefix expression, if one exists. Otherwise returns -1.
int endPre(string strExp, int first)
{
	int last = strExp.length() - 1;

	if (first < 0 || first > last)
		return -1;

	char ch = strExp[first];
	// if ch is an identifier (single digit 0-9 or single letter A-z) (ASCII 48-57, 65-122)
	if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 122)) 
		return first;
	else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') // ch is an operator
	{
		// Find the end of the first prefix expression.
		int firstEnd = endPre(strExp, first + 1);

		// If the end of the first prefix expression was found, find the end of the second.
		if (firstEnd > -1)
			return endPre(strExp, firstEnd + 1);
	}
	return -1;
}

bool isPrefix(string strExp)
{
	char lastChar = endPre(strExp, 0);
	// The prefix expression must exist, and the entire string must be a prefix expression.
	return (lastChar >= 0 && lastChar == strExp.length() - 1);
}

string evaluatePrefix(string strExp)
{
	int strLength = strExp.length();

	if (strLength == 1)
		return strExp;
	else
	{
		char op = strExp[0];
		int endFirst = endPre(strExp, 1);
		string operand1 = evaluatePrefix(strExp.substr(1, endFirst));
		int endSecond = strLength - endFirst+1;// - 77; WTF IS GOING ON HERE
		string operand2 = evaluatePrefix(strExp.substr(endFirst + 1, endSecond));
		return operand1 + op + operand2;

	}
}