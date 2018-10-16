/**********************************************************************************************
Donald J Freiday
CS2 : Assignment 1 : Test the account class from handout
***********************************************************************************************/

// Class declaration file: account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class account
{
public:
	// Constructors
	account();
	account(const string &password, double balance);
	account(const account &a);

	// Accessor
	// note to self: second const prevents client code from modifying object
	double getBalance(const string &password) const; 

	// Modifiers
	int setPassword(const string &password, const string &newPassword);
	double deposit(const string &password, double amount);
	double withdraw(const string &password, double amount);

	// Assignment
	const account& operator = (const account &a);

private:
	// Data members
	string myPassword;
	double myBalance;
};

#endif