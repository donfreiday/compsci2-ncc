// Donald J Freiday
// CS2 : Assignment 2 : Rational Class
// gcd.cpp : Implementation of GCD

int gcd(int a, int b) // assumes nonzero arguments
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
	/*bool flag = false;
	if (a < 0 && b >= 0)
		a = -a;
	if (b<0 && a>0)
		b = -b;
	if (b < 0 && a == 0)
		return -b;
	if (a < 0 && b < 0)
	{
		flag = true;
		a = -a;
		b = -b;
	}
	int temp;
	while (b != 0)
	{
		temp = a;
		a = b;
		b = temp%b;
	}
	if (flag)
	{
		return -a;
	}
	return a;*/
}
