// ToyBox.h

#ifndef _TOYBOX_H
#define _TOYBOX_H
#include "PlainBox.h" // include superclass, aka parent class, aka base class

enum Color { BLACK, RED, BLUE, GREEN, YELLOW, WHITE};

template<class ItemType>
class ToyBox : public PlainBox<ItemType> // public inheritance from PlainBox
{
private:
	Color boxColor;

public:
	ToyBox();
	ToyBox(const Color& theColor);
	ToyBox(const ItemType& theItem, const Color& theColor);

	Color getColor() const;
};
#include "ToyBox.cpp"
#endif