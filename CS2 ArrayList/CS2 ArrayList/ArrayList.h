// @file ArrayList.h

#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 100;
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItems;
public:
	ArrayList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
};
#include "ArrayList.cpp"
#endif