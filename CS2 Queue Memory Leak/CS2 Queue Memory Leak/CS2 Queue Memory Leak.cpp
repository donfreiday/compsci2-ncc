// CS2 Queue Memory Leak.cpp : Defines the entry point for the console application.
//
// uncomment destructor in Queue.cpp to fix

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	for (int i = 0; i < 1000000; i++)
	{
		Queue<string> q;
		q.enqueue("dsgdsggggggggggggggggggggggggggggggggggggggg");
	}
	cin.get();

	return 0;
}