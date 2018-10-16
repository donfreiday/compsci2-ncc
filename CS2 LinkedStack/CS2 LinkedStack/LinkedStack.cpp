// @file LinkedStack.cpp

#include "LinkedStack.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	Node<ItemType>* origChainPtr = aStack.topPtr;

	if (origChainPtr == nullptr)
		topPtr = nullptr;
	else
	{
		topPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());
		Node<ItemType>* newChainPtr = topPtr;

		while (origChainPtr->getNext() != nullptr)
		{
			origChainPtr = origChainPtr->getNext();
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();

		}
		newChainPtr->setNext(nullptr);
	}
}//end copy constructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	if (isEmpty())
		return false;
	Node<ItemType>* nodeToDeletePtr = topPtr;
	topPtr = topPtr->getNext();
	nodeToDeletePtr->setNext(nullptr);
	delete nodeToDeletePtr;
	nodeToDeletePtr = nullptr;
	return true;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw PrecondViolatedExcep("peek() called on empty stack");
	return topPtr->getItem();
}