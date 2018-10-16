// PlainBox.h

#ifndef _PLAIN_BOX_H
#define _PLAIN_BOX_H
#include "BoxInterface.h"

template<class ItemType> // Indicates that this is a template definition

class PlainBox : public BoxInterface<ItemType>
{
protected:
	ItemType item;

public:
	PlainBox();

	PlainBox(const ItemType& theItem);

	void setItem(const ItemType& theItem);

	ItemType getItem() const; // const indicates no change to objects data members
};

// A template class will not be compiled until the compiler sees the client's instantiation
// of the template and knows the actual data type corresponding to the data-type parameter ItemType.
#include "PlainBox.cpp" 
#endif