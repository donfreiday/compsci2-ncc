// @file ArrayStack.cpp
#include <cassert>
#include "ArrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() :top(-1)
{};

// Copy constructor and destructor are compiler supplied

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	if (top < MAX_STACK - 1)
	{
		top++;
		items[top] = newEntry;
		return true;
	}
	return false;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	if (!isEmpty())
	{
		top--;
		return true;
	}
	return false;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("peek() called on empty stack");
	return items[top];
}