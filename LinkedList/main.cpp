#include <iostream>
#include "linkedList.h"

int main() {
	LinkedList<int> l;
	l.addAtBeginning(2);
	l.addAtBeginning(5);
	l.addAtBeginning(3);
	l.printList();

	Node<int> * secondFromEnd = l.mthNodeFromEnd(0);
	std::cout<<secondFromEnd->getNodeData()<<std::endl;
	return 0;
}