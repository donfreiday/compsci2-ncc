// CS2 Ch3 ArrayBag.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize() << " items.\n";

	vector<string> bagItems = bag.toVector();
	int numEntries = (int)bagItems.size();
	for (int i = 0; i < numEntries; i++)
		cout << bagItems[i] << " ";
	cout << "\n\n";
} // end displayBag

void bagTester(ArrayBag<string>& bag)
{
	cout << "isEmpty(): returns " << bag.isEmpty() << "; should be 1 (true).\n";
	displayBag(bag);

	string items[] = { "one", "two", "three", "four", "five", "one" };
	cout << "Add six items to the bag:\n";
	for (int i = 0; i < 6; i++)
	{
		bag.add(items[i]);
	}
	displayBag(bag);
	cout << "isEmpty(): returns " << bag.isEmpty() << "; should be 1 (true).\n";
	cout << "getCurrentSize(): returns " << bag.getCurrentSize() << "; should be 6.\n";

	cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;

	cout << "\ncontains(\"three\"): returns " << bag.contains("three") << ", should be 1 (true)\n";
	cout << "contains(\"ten\"): returns " << bag.contains("ten") << ", should be 0 (false)\n";

	cout << "\ngetFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << ", should be 2\n";
	cout << "\nremove(\"one\"): returns " << bag.remove("one") << ", should be 1 (true)\n";
	cout << "\ngetFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << ", should be 1\n";
	cout << "\nremove(\"one\"): returns " << bag.remove("one") << ", should be 1 (true)\n";
	cout << "\ngetFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << ", should be 0\n";
	displayBag(bag);
} // end bagTester

int main()
{
	ArrayBag<string> bag;
	bagTester(bag);
	cin.get();
	return 0; 
}