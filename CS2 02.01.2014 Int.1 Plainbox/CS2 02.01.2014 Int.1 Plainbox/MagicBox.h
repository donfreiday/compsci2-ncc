// MagicBox.h
#ifndef _MAGICBOX_H
#define _MAGICBOX_H

#include "PlainBox.h"

template<class ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
	bool firstItemStored;

public:
	MagicBox();
	MagicBox(const ItemType& theItem);

	void setItem(const ItemType& theItem);
};
#include "MagicBox.cpp"
#endif