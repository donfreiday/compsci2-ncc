// @file LinkedBag.h

#ifndef _LINKED_BAG_H
#define _LINKED_BAG_H

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>&aBag);
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	int getFrequencyOf(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

#include "LinkedBag.cpp"
#endif