//@file ArrayStack.h
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "StackInterface.h"
#include "PrecondViolatedExcep.h"

const int MAX_STACK = 5; // low value for testing purposes

template<class ItemType>
class ArrayStack :public StackInterface<ItemType>
{
private:
	ItemType items[MAX_STACK];
	int top;
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	// exception specifications are deprecated in C++11. 
	// Throwing a different exception will not terminate the program
	ItemType peek() const throw(PrecondViolatedExcep); 
};

#include "ArrayStack.cpp"
#endif