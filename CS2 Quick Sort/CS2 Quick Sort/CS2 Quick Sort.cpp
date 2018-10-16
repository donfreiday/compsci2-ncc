// CS2 Quick Sort.cpp : Defines the entry point for the console application.
//
// 

#include <iostream>

#define MIN_SIZE 10

template<class ItemType>
void insertionSort(ItemType theArray[], int n);

template<class ItemType>
void sortFirstMiddleLast(ItemType theArray[], int first, int mid, int last);

template<class ItemType>
int partition(ItemType theArray[], int first, int last);

template<class ItemType>
void quickSort(ItemType theArray[], int first, int last);

int main()
{
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

// Arranges the first, middle and last entries in an array in ascending order
template<class ItemType>
void sortFirstMiddleLast(ItemType theArray[], int first, int mid, int last)
{
	if (theArray[first] > theArray[mid])
		std::swap(theArray[first], theArray[mid]);
	if (theArray[mid] > theArray[last])
		std::swap(theArray[mid], theArray[last]);
	if (theArray[first] > theArray[mid])
		std::swap(theArray[first], theArray[mid]);
}

template<class ItemType>
int partition(ItemType theArray[], int first, int last)
{
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(theArray, first, mid, last);
	std::swap(theArray[mid], theArray[last - 1]);
	int pivotIndex = last - 1;
	int pivot = theArray[pivotIndex];

	// determine the regions S1 and S2
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool done = false;
	while (!done)
	{
		while (theArray[indexFromLeft] < pivot)
			indexFromLeft = indexFromLeft + 1;
		while (theArray[indexFromright] > pivot)
			indexFromRight = indexFromRight - 1;
		if (indexFromLeft < indexFromRight)
	}


}

template<class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
	if (last - first + 1 < MIN_SIZE)
		insertionSort(theArray, first, last);
	else
	{
		// Create the partition: S1 | Pivot | S2
		int pivotIndex = partition(theArray, first, last);
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}
}
