// PlainBox.cpp
// NOTE: do not add to source in IDE, is an external dependency; adding it to Source Files
// will break the project (in visual studio 2013 at least)

template <class ItemType>
PlainBox<ItemType>::PlainBox()
{
}

template <class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem)
{
	item = theItem;
}

template <class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
	item = theItem;
}

template <class ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
	return item;
}