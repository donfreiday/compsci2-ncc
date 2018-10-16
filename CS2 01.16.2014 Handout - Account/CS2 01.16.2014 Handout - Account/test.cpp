/**********************************************************************************************
Donald J Freiday
CS2 : Assignment 1 : Test the account class from handout
***********************************************************************************************/

#include <iostream>
#include "account.h"

using namespace std;

int main()
{
	cout << "Donald J. Freiday\nCS2 : Assignment 1 : Test the account class from handout\n" << endl;
	account defaultAccount;
	account billGates("philanthropy", 100000.00);

	cout << "defaultAccount getBalance: $"
		<< defaultAccount.getBalance("") << endl;

	cout << "defaultAccount setPassword to \"freedom\" (0 indicates success): "
		<< defaultAccount.setPassword("", "freedom") << endl;

	cout << "defaultAccount setPassword to \"liberty\" with incorrect password: "
		<< defaultAccount.setPassword("", "liberty") << endl;

	cout << "defaultAccount deposit $15 with password \"freedom\": $"
		<< defaultAccount.deposit("freedom", 15) << endl;

	cout << "\nbillGates getBalance with incorrect password: $"
		<< billGates.getBalance("philanthroyp") << endl;

	cout << "billGates getBalance with correct password: $"
		<< billGates.getBalance("philanthropy") << endl;

	cout << "\nbillGates withdraw 500 with incorrect password: $"
		<< billGates.withdraw("password", 500) << endl;

	cout << "billGates withdraw 500 with correct password: $"
		<< billGates.withdraw("philanthropy", 500) << endl;

	cout << "billGates withdraw -500 with correct password: $"
		<< billGates.withdraw("philanthropy", -500) << endl;

	cout << "billGates withdraw overdraft with correct password: $"
		<< billGates.withdraw("philanthropy", 999999999999999) << endl;

	cout << "\nbillGates deposit 20000 with incorrect password: $"
		<< billGates.deposit("asdfsad", 20000) << endl;

	cout << "billGates deposit 20000 with correct password: $"
		<< billGates.deposit("philanthropy", 20000) << endl;

	cout << "billGates deposit -20000 with correct password: $"
		<< billGates.deposit("philanthropy", -20000) << endl;

	cout << "\nbillGates actual net worth is 72 billion dollars per Google: $"
		<< billGates.deposit("philanthropy", 72000000000.99) << endl;

	cout << "\nTest overloaded assignment operator by assigning billGates to defaultAccount\n";
	defaultAccount = billGates;
	cout << "defaultAccount getBalance with password \"philanthropy\": $"
		<< defaultAccount.getBalance("philanthropy") << endl;

	cout << "\nTest constructor account(const account &a)\n";
	account newAccount(defaultAccount);
	cout << "Meet the newAccount, same as the old account: $"
		<< newAccount.getBalance("philanthropy") << endl;

	cout << "\n\nHit Enter to continue";
	cin.get(); // Keep the console window open to view output
	return 0;
}