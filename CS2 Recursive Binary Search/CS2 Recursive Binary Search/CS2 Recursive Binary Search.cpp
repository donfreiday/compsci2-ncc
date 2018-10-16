// CS2 Recursive Binary Search.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

int findLargest(int anArray[], int size);

int main()
{
	int nums[10] = { 1, 2, 3, 43, 55, 66, 75, 80, 90, 400 };
	cout << "The largest number in array nums is " << findLargest(nums, 10);
	cin.get();
}

int findLargest(int anArray[], int size)
{
	int L;
	if (size == 0)
		return -1;
	else if (size > 1)
	{
		L = findLargest(anArray, size - 1);
		return L > anArray[size - 1] ? L : anArray[size - 1];
	}
	else
		return anArray[size - 1];
}