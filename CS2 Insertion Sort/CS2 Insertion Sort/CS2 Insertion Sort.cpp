// CS2 Insertion Sort.cpp : Defines the entry point for the console application.
// o(n^2) worst case, o(n) best case

#include <iostream>

template<class ItemType>
void insertionSort(ItemType theArray[], int n);

int main()
{
	int array[] = { 5, 6, 1, 2, 3, 4 };
	insertionSort(array, 6);
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << std::endl;
	return 0;

	return 0;
}

template<class ItemType>
void insertionSort(ItemType theArray[], int n)
{
	for (int unsorted = 1; unsorted < n; unsorted++)
	{
		ItemType nextItem = theArray[unsorted];
		int loc = unsorted;
		while ((loc>0) && (theArray[loc - 1] > nextItem))
		{
			theArray[loc] = theArray[loc - 1];
			loc--;
		}
		theArray[loc] = nextItem;
	}
}
