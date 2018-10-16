// @file main.cpp

#include <iostream>
#include "LinkedStack.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
void displayStack(ItemType aStack);

int main()
{

	LinkedStack<int>* stackPtr = new LinkedStack<int>();
	cout << "LinkedStack<int>* stackPtr = new LinkedStack<int>();\n";
	cout << "  stackPtr->isEmpty() returns " << (stackPtr->isEmpty() ? "true" : "false") << endl;
	try 
	{
		stackPtr->peek();
	}
	catch (PrecondViolatedExcep e) 
	{
		cout << e.what() <<endl;
	}

	cout << "  stackPtr->push(7) returns " << (stackPtr->push(7) ? "true" : "false") << endl;
	cout << "  stackPtr->peek() returns " << stackPtr->peek() << endl;
	cout << "  stackPtr->isEmpty() returns " << (stackPtr->isEmpty() ? "true" : "false") << endl;
	cout << "  stackPtr->pop() returns " << (stackPtr->pop() ? "true" : "false") << endl;
	cout << "  stackPtr->isEmpty() returns " << (stackPtr->isEmpty() ? "true" : "false") << endl;

	for (int i = 0; i < 7; i++) // overfill stack assuming MAX_STACK <= 5
	{
		cout << "  stackPtr->push(" << i << ") returns " << (stackPtr->push(i) ? "true" : "false") << endl;
	}
	cout << "  displayStack(*stackPtr):\n";
	displayStack(*stackPtr);

	cout << "\nLinkedStack<int> copyStack(*stackPtr);\n";
	LinkedStack<int> copyStack(*stackPtr);
	cout << "  copyStack.isEmpty() returns " << (copyStack.isEmpty() ? "true" : "false") << endl;
	cout << "  copyStack.peek() returns " << copyStack.peek() << endl;
}

template<class ItemType>
void displayStack(ItemType aStack)
{
	while (!aStack.isEmpty())
	{
		cout << aStack.peek() << endl;
		aStack.pop();
	}
}