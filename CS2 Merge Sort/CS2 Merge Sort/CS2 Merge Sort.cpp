// CS2 Merge Sort.cpp : Defines the entry point for the console application.
// O(n * log(n))

#include <iostream>

const int MAX_SIZE = 1000;

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last);

template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last);

int main()
{
	int array[] = { 3, 2, 1, 4 , 99, 21, 24, 2526};
	mergeSort(array, 0, 7);
	std::cout << "\n\n";
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << "\n";
	return 0;
}

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
	ItemType tempArray[MAX_SIZE];

	// local indices to indicate the subarrays
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	// while both subarrays are not empty copy the smaller item into the temporary array
	int index = first1; // next available location in temporary array
	while (first1 <= last1 && first2 <= last2)
	{
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
		}
		index++;
	}

	// finish off the first subarray
	while (first1 <= last1)
	{
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}

	// finish off the second subarray
	while (first2 <= last2)
	{
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}

	//copy temporary array into passed array
	for (index = first; index <= last; index++)
		theArray[index] = tempArray[index];
} // end merge

template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
	std::cout << "mergeSort(theArray, " << first << ", " << last << ") : ";
	for (int i = 0; i <=last; i++)
		std::cout << theArray[i]<< " ";
	std::cout << "\n\n";
	if (first < last)
	{
		// sort each half
		int mid = first + (last - first) / 2;
		mergeSort(theArray, first, mid);
		mergeSort(theArray, mid + 1, last);

		std::cout << "merge(theArray, " << first << ", " << mid << ", "<< last << ") : ";
		for (int i = 0; i <= last; i++)
			std::cout << theArray[i] << " ";
		std::cout << "\n\n";
		merge(theArray, first, mid, last);
	}
}