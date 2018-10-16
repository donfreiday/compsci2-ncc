// @file main.cpp

#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
	cout << "SortedList<string> list; \n";
	SortedList<string> list;

	cout << "list.isEmpty :" << (list.isEmpty() ? "true" : "false") << endl;

	list.insertSorted("Mario");
	list.insertSorted("Link");
	list.insertSorted("Zelda");
	list.insertSorted("Toad");
	list.insertSorted("Bowser");

	cout << list.toString();
	cout << "list.isEmpty :" << (list.isEmpty() ? "true" : "false") << endl << endl;

	list.removeSorted("Toad");
	cout << endl << list.toString();

	cout << endl << list.getEntry(3) << endl;
	
	cout << "\nList length: " << list.getLength() << endl;

	cout << "\nlist.getPosition(\"Mario\") :" << list.getPosition("Mario") <<endl;

	cout<<"list.remove(3)\n\n";
	list.remove(3);
	cout << list.toString();

	return 0;
}