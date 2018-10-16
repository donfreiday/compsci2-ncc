#include <iostream>
#include <string>

using namespace std;

int iterativeFactorial(int n);
int recursiveFactorial(int n);

string iterativeReverse(string s);
string reverse(string s);

int main()
{
	string s;
	cout << "Enter a string to reverse: ";
	cin >> s;

	cout << endl << reverse(s) << endl << iterativeReverse(s);

	cin.ignore();
	cin.get();
}

int iterativeFactorial(int n)
{
	if (n == 0)
		return 1;

	for (int i = n - 1; i > 0; i--)
		n = n*i;

	return n;
}

int recursiveFactorial(int n)
{
	if (n == 0) // base case
		return 1;

	return n*(recursiveFactorial(n - 1)); // n-1 diminishes the data set
}

string iterativeReverse(string s)
{
	string temp = "";
	for (int i = s.length(); i >= 0; i--)
		temp += s[i];
	return temp;
}

string reverse(string s)
{
	if (s.length() == 1 || s.length() == 0)
		return s;
	else
		return reverse(s.substr(1, s.length() - 1)) + s[0];
}