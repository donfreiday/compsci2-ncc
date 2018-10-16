#ifndef _ARRAY_BAG_H
#define _ARRAY_BAG_H

#include "BagInterface.h"

#include <vector>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6;
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItems;

	int getIndexOf(const ItemType& target) const;

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

#include "ArrayBag.cpp"
#endif