#include "ArrayBag.h"
#include <iostream> //debug
/* Default constructor, replaced with version using initializers below
template<class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
}*/

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

// private member fx
// my own implementation rather than the textbooks
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i] == target)
			return i;
	}
	return -1; // not found
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	if (itemCount < maxItems)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}
	return itemCount < maxItems;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
	return bagContents;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
			frequency++;
		curIndex++;
	}
	return frequency;
}

// my own implementation rather than the textbooks
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i] == anEntry)
			return true;
	}
	return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
	return canRemoveItem;
}

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}