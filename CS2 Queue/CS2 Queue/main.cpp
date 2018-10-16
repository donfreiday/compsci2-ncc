// @file main.cpp// Donald J Freiday
// CISC 125 : Computer Science 2
// Queue
// @file main.cpp

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main()
{
	cout << "Donald J Freiday \nCISC 125 : Computer Science 2 \nQueue \n\n";
	Queue<string> queue;
	cout << "Queue<string> queue; \n";
	cout << "queue.isEmpty() returns " << (queue.isEmpty() ? "true" : "false") << endl;
	cout << "queue.dequeue() returns " << (queue.dequeue() ? "true" : "false") << endl;
	try
	{
		cout << "queue.peekFront() returns " << queue.peekFront() << endl;
	}
	catch (PrecondViolatedExcep e)
	{
		cout << e.what() << endl;
	}
	cout << "queue.enqueue(\"Ashley\") returns " << (queue.enqueue("Ashley") ? "true" : "false") << endl;
	cout << "queue.enqueue(\"Bob\") returns " << (queue.enqueue("Bob") ? "true" : "false") << endl;
	cout << "queue.enqueue(\"Caitlin\") returns " << (queue.enqueue("Caitlin") ? "true" : "false") << endl;
	cout << "queue.enqueue(\"Daniel\") returns " << (queue.enqueue("Daniel") ? "true" : "false") << endl;
	cout << "queue.enqueue(\"Erika\") returns " << (queue.enqueue("Erika") ? "true" : "false") << endl;
	cout << "queue.toString() returns \n"<<queue.toString();
	cout << "queue.dequeue() returns " << (queue.dequeue() ? "true" : "false") << endl;
	cout << "queue.peekFront() returns " << queue.peekFront() << endl;
	cout << "Queue<string>* copyQueue = new Queue<string>(queue); \n";
	Queue<string>* copyQueue = new Queue<string>(queue);
	cout << "copyQueue->toString() returns \n" << copyQueue->toString();
	cout << "copyQueue->dequeue() returns " << (copyQueue->dequeue() ? "true" : "false") << endl;
	cout << "copyQueue->peekFront() returns " << copyQueue->peekFront() << endl;
	delete copyQueue;
	copyQueue = nullptr;
	cout << "queue.toString() returns \n" << queue.toString();

	return 0;
}
