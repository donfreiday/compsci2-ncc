// MagicBox.cpp

template<class ItemType>
MagicBox<ItemType>::MagicBox()
{
	PlainBox<ItemType>();
	firstItemStored = false;
}

template<class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& theItem)
{
	firstItemStored = false;
	setItem(theItem);
}

template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
	if (!firstItemStored)
	{
		item = theItem;
		firstItemStored = true;
	}
}
