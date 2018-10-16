/**********************************************************************************************
Donald J Freiday
CS2 : Assignment 1 : Test the account class from handout
***********************************************************************************************/

#include "account.h"
#include <string>

using namespace std;

account::account()
{
	myPassword = "";
	myBalance = 0.00;
}

account::account(const string &password, double balance)
{
	myPassword = password;
	myBalance = balance;
}

account::account(const account &a)
{
	myPassword = a.myPassword;
	myBalance = a.myBalance;
}

double account::getBalance(const string &password) const
{
	if (password == myPassword)
		return myBalance;
	else
		return -1;
}

double account::withdraw(const string &password, double amount)
{
	if (password == myPassword)
	{
		if ((amount >= 0) && (amount <= myBalance))
		{
			myBalance = myBalance - amount;
			return myBalance;
		}
		else
			return -2; // Invalid amount
	}
	else
		return -1; // Invalid password
}

double account::deposit(const string &password, double amount)
{
	if (password == myPassword)
	{
		if (amount >= 0)
		{
			myBalance += amount;
			return myBalance; // this was missing in my notes from class
		}
		else
			return -2; // Cannot deposit a negative amount
	}
	else
		return -1; // Invalid password
}

const account& account::operator = (const account &a)
{
	if (this != &a)
	{
		myPassword = a.myPassword;
		myBalance = a.myBalance;
	}
	return *this;
}

int account::setPassword(const string &password, const string &newPassword) 
{
	if (password == myPassword)
	{
		myPassword = newPassword;
		return 0;
	}
	return -1;

}