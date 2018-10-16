// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file main.cpp

#include <iostream>
#include "LinkedList.h"

using namespace std;

template<class ListType>
void displayList(const ListType& aList);

int main()
{
	cout << "Donald J Freiday \n"
		<< "CISC 125 : Computer Science 2 \n"
		<< "LinkedList \n\n";

	cout << "LinkedList<int> list; \n";
	LinkedList<int> list;

	cout << "list.isEmpty() returns " 
		<< (list.isEmpty() ? "true" : "false") << endl;
	cout << "list.getLength() returns " 
		<< list.getLength() << endl;
	cout << "list.getEntry(1) throws ";
	try
	{
		list.getEntry(1);
	}
	catch (PrecondViolatedExcep e)
	{
		cout << e.what() << endl;
	}
	cout << "list.setEntry(777, 7) throws ";
	try
	{
		list.setEntry(777, 7);
	}
	catch (PrecondViolatedExcep e)
	{
		cout << e.what() << endl;
	}

	for (int i = 1; i <= 5; i++)
	{
		cout << "list.insert(" << i << ", " << i << ")\n";
		list.insert(i, i);
	}
		
	cout << "list.isEmpty() returns " 
		<< (list.isEmpty() ? "true" : "false") << endl;
	cout << "list.getLength() returns " 
		<< list.getLength() << endl;
	displayList(list);

	cout << "list.remove(3) \n";
	list.remove(3);
	displayList(list);

	cout << "list.insert(3, 7) \n"
		<< "list.insert(6, 6); \n";
	list.insert(3, 7);
	list.insert(6, 6);
	displayList(list);

	cout << "list.setEntry(3,3) \n";
	list.setEntry(3, 3);
	displayList(list);

	cout << "LinkedList<int> list2(list); \n";
	LinkedList<int> list2(list);
	displayList(list2);

	cout << "list2.clear() \n";
	list2.clear();

	cout << "list2.isEmpty() returns "
		<< (list2.isEmpty() ? "true" : "false") << endl;
	cout << "list2.getLength() returns "
		<< list2.getLength() << endl;
	displayList(list2);

	return 0;
}

template<class ListType>
void displayList(const ListType& aList)
{
	for (int i = 1; i <= aList.getLength(); i++)
		cout << i << ") " << aList.getEntry(i) << endl;
}
