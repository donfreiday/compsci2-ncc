// CS2 Ch4 LinkedBag 
// @file main.cpp

#include <iostream>
#include "LinkedBag.h"

using namespace std;

template<class ItemType>
void printVector(const vector<ItemType>& v);

int main()
{
	LinkedBag<int> lb;

	for (int i = 1; i <= 11; i++)
		lb.add(i);
	
	printVector(lb.toVector());

	lb.remove(11);
	lb.remove(1);
	lb.remove(77);

	//lb.clear(); 
	//if (lb.isEmpty())
	//	cout << "\nclear() works\n\n";

	printVector(lb.toVector());

	LinkedBag<int> lb2(lb);
	printVector(lb2.toVector());

	cin.get();
	return 0;
}

template<class ItemType>
void printVector(const vector<ItemType>& v)
{
	cout << "Vector of size: " << v.size() << endl;
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << "  ";
	cout << "\n\n";
}