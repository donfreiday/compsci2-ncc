// @file ArrayList.cpp
#include "ArrayList.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = newPosition >= 1 && newPosition <= itemCount + 1 && itemCount < maxItems;
	if (ableToInsert)
	{
		for (int pos = itemCount; pos >= newPosition; pos--)
			items[pos] = items[pos - 1];

		items[newPosition - 1] = newEntry;
		itemCount++;
	}
	return ableToInsert;
}

// stub
template<class ItemType>
bool ArrayList<ItemType>::remove(int position)
{
	if (position >= 1 && position <= itemCount)
	{
		for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount; fromIndex++, toIndex++)
			items[toIndex] = items[fromIndex];
		itemCount--;
		return true;
	}
	return false;
}

template<class ItemType>
void ArrayList<ItemType>::clear()
{
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	if (position >= 1 && position <= itemCount)
		return items[position - 1];
	else
		throw(PrecondViolatedExcep("getEntry() called with an empty list or invalid position."));
}

template<class ItemType>
void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
	if (position >= 1 && position <= itemCount)
		items[position - 1] = newEntry;
	else
		throw(PrecondViolatedExcep("setEntry() called with an empty list or invalid position."));
}