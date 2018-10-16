// test.cpp

#include <iostream>
#include <string>
#include "MagicBox.h"
#include "PlainBox.h"
#include "ToyBox.h"

using namespace std;

int main()
{
	PlainBox<double> plainBoxDouble(2.0);
	cout << "PlainBox holding a double: " << plainBoxDouble.getItem() << endl;

	PlainBox<string> plainBoxString("here is a string");
	cout << "PlainBox holding a string: " << plainBoxString.getItem() << endl;

	ToyBox<string> redbox(RED);
	cout << "\nA toybox with color " << redbox.getColor() << " and item "<<redbox.getItem()<<endl;
	redbox.setItem("SNES");
	cout << "A toybox with color " << redbox.getColor() << " and item " << redbox.getItem() << endl;

	MagicBox<string> magicbox("Super Mario 3");
	cout << "\nA magic box that turns anything into Super Mario 3! : " << magicbox.getItem() << endl;
	magicbox.setItem("A healthy apple");
	cout << "\nA magic box that turns anything into Super Mario 3! : " << magicbox.getItem() << endl;

	PlainBox<string> cardBox;
	cardBox = MagicBox<string>("Queen of Hearts");
	cardBox.setItem("\nJack of Spades"); // because cardBox is of type PlainBox<string>, PlainBox's setItem is used
	cout << cardBox.getItem() << endl;

	BoxInterface<string>* someBoxPtr = new MagicBox<string>("NES");
	cout<<"\nEven though the pointer is of type BoxInterface<string>, because"
		<< " getItem() is a\nvirtual method, it will call magicbox's implementation: "<<someBoxPtr->getItem();

	cin.get();
}