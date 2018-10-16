// Donald J Freiday
// CISC 125 : Computer Science 2
// Node Assignment (Chapter 4, pages 136-137)
// @file main.cpp : Node client code (test program)

#include "Node.h"
#include <iostream>
#include <string>

template<class ItemType>
void printNode(const Node<ItemType>& node);

template<class ItemType>
void traceNodes(const Node<ItemType>& node);

using namespace std;

int main()
{
	cout << "Donald J Freiday \n"
		<< "CISC 125 : Computer Science 2 \n"
		<< "Node Assignment (Chapter 4, pages 136-137) \n\n";

	cout << "Test default constructor: Node<int> node1";
	Node<int> node1;
	printNode(node1);

	cout << "Test mutator function: node1.setItem(1)";
	node1.setItem(1);
	printNode(node1);

	cout << "Test overloaded constructor: Node<int> node2(2)";
	Node<int> node2(2);
	printNode(node2);

	cout << "Test mutator function: node2.setNext(&node1)";
	node2.setNext(&node1);
	printNode(node2);

	Node<int> node3(3, &node2);
	cout << "Test overloaded constructor: Node<int> node3(3, &node2)";
	printNode(node3);

	cout << "Create a few more Nodes and trace through them:\n"
		<< " Node<int> node4(4, &node3) \n"
		<< " Node<int> node5(5, &node4) \n"
		<< " Node<int> node6(7, &node5) \n\n";
	Node<int> node4(4, &node3);
	Node<int> node5(5, &node4);
	Node<int> node6(7, &node5);
	cout << "traceNodes(node6):";
	traceNodes(node6);

	cin.get();

	return 0;
} // end main

template<class ItemType>
void printNode(const Node<ItemType>& node)
{
	cout << "\n getItem(): " << node.getItem()
		<< "\n getNext(): " << node.getNext()
		<< "\n getNext() == nullptr: "
		<< (node.getNext() == nullptr ? "true" : "false")
		<< "\n\n";
} // end printNode

template<class ItemType>
void traceNodes(const Node<ItemType>& node)
{
	const Node<ItemType>* nodePtr = &node;

	cout << "\n Tracing Nodes, format is Address:Item -> next\n  " 
		<< nodePtr << ":" << nodePtr->getItem();

	while ((nodePtr = nodePtr->getNext()) != nullptr)
		cout << " -> " << nodePtr << ":" << nodePtr->getItem();

	cout << "\n\n";
} //  end traceNodes