// O(n^2)
#include <iostream>

template<class ItemType>
void bubbleSort(ItemType theArray[], int n);

int main()
{
	int array[] = { 5, 6, 1, 2, 3, 4 };
	bubbleSort(array, 6);
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		std::cout << array[i] << std::endl;
	return 0;
}

template<class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
	bool sorted = false;
	int last = n - 1;
	while (!sorted && last>1)
	{
		sorted = true;
		for (int i = 0; i < last; i++)
		{
			if (theArray[i] > theArray[i + 1]) // switch the  > to < to invert sort
			{
				std::swap(theArray[i], theArray[i + 1]);
				sorted = false;
			}
		}
		last--;
	}
}