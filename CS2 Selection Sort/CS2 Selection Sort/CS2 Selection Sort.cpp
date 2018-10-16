// O(n^2)

#include <iostream>

template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size);

template<class ItemType>
void selectionSort(ItemType theArray[], int n);

using namespace std;

int main()
{
	int array[] = { 7, 5, 3, 4, 2, 1, 6 };
	selectionSort(array, 7);

	// The sizeof trick doesn't work in functions called with an array parameter
	// because the array decays to a pointer
	cout << "Array is of size: " << sizeof(array) / sizeof(array[0]) << endl;
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
		cout << array[i] << endl;
	return 0;
}

template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
	for (int last = n - 1; last >= 1; last--)
	{
		int largest = findIndexOfLargest(theArray, last + 1);
		swap(theArray[largest], theArray[last]);
	}
}

template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
	int indexOfLargest = 0;
	for (int i = 1; i < size; i++)
	{
		if (theArray[i]>theArray[indexOfLargest])
			indexOfLargest = i;
	}
	return indexOfLargest;
}