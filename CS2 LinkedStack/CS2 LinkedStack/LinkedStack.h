// @file LinkedStack.h

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "PrecondViolatedExcep.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
	Node<ItemType>* topPtr;
public:
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);
	virtual ~LinkedStack();

	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const throw(PrecondViolatedExcep);
};
#include "LinkedStack.cpp"
#endif