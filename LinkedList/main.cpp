#include <iostream>
#include "linkedList.h"

int main() {
	LinkedList<int> l;
	// making the list explicitly cyclic
	l.addAtBeginning(2);
	l.addAtBeginning(5);
	l.addAtBeginning(8);
	std::cout<<l.isCyclic()<<std::endl;
	return 0;
}