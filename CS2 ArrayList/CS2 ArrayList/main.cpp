// @file main.cpp

#include <iostream>
#include <string>
#include "ArrayList.h"

using namespace std;

template<class ItemType>
void displayList(const ItemType& aList);

int main()
{
	cout << "ArrayList<string>* listPtr = new ArrayList<string>();" << endl;
	ArrayList<string>* listPtr = new ArrayList<string>();
	cout << "listPtr->isEmpty() returns " << (listPtr->isEmpty()?"true":"false")<<endl;
	cout << "listPtr->getLength() returns " << listPtr->getLength() << endl;
	cout << "listPtr->insert(77, \"apple\") returns " << (listPtr->insert(77, "apple") ? "true" : "false") << endl;
	cout << "listPtr->insert(1, \"apple\") returns " << (listPtr->insert(1, "apple") ? "true" : "false") << endl;
	cout << "listPtr->getEntry(1) returns " << listPtr->getEntry(1) << endl;
	try
	{
		cout << "listPtr->getEntry(2) returns " << listPtr->getEntry(2) << endl;
	}
	catch (PrecondViolatedExcep e)
	{
		cout << "listPtr->getEntry(2) throws\n"<<e.what()<<endl;
	}
	cout << "listPtr->insert(1, \"banana\") returns " << (listPtr->insert(1, "banana") ? "true" : "false") << endl;
	cout << "listPtr->insert(1, \"cranberry\") returns " << (listPtr->insert(1, "cranberry") ? "true" : "false") << endl;
	cout << "displayList<string>(*listPtr):\n";
	displayList(*listPtr);
	try
	{
		cout << "listPtr->setEntry(5,\"foo\");\n";
		listPtr->setEntry(5, "foo");
	}
	catch (PrecondViolatedExcep e)
	{
		cout << "listPtr->setEntry(5,\"foo\") throws\n" << e.what() << endl;
	}
	cout << "listPtr->setEntry(3,\"avocado\");\n";
	listPtr->setEntry(3, "avocado");
	cout << "displayList<string>(*listPtr):\n";
	displayList(*listPtr);
	cout << "listPtr->remove(5) returns " << (listPtr->remove(5) ? "true" : "false") << endl;
	cout << "listPtr->remove(2) returns " << (listPtr->remove(2) ? "true" : "false") << endl;
	cout << "displayList<string>(*listPtr):\n";
	displayList(*listPtr);
	return 0;
}

template<class ItemType>
void displayList(const ItemType& aList)
{
	cout << "LIST:\n";
	for (int i = 1; i <= aList.getLength(); i++)
		cout << " "<<i<<") "<<aList.getEntry(i) << endl;
}