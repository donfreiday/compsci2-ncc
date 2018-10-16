// BoxInterface.h

#ifndef _BOX_INTERFACE_H
#define _BOX_INTERFACE_H

template<class ItemType>
class BoxInterface
{
public:
	virtual ~BoxInterface() {}
	virtual void setItem(const ItemType& theItem) = 0; // pure virtual methods
	virtual ItemType getItem() const = 0;
};

#endif