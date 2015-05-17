/* 
* Class : LinkedList 
* ------------------------------------------
* Defines the implementation of Linked List 
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "node.h"

template <typename ElemType>
class LinkedList {
	public : 
		/*
		* Function : Constructor function for the linked list class
		* ---------------------------------------------------------
		* Takes in no arguments
		*/
		LinkedList();
		/*
		* Function : addAtBeginning(Data that the node is to hold)
		* --------------------------------------------------------
		* Adds a new node at the beginning of the linked list with
		* the data that is passed as the parameter of this routine.
		*/
		void addAtBeginning(ElemType data);

		/*
		* Function : mthFromLast()
		* --------------------------------------------------
		* Returns the Node which is present
		* at the position m from the end of the 
		* list.
		* Uses an algorithm assuming that the length
		* of the linked list that is number of nodes in the 
		* linked list is not explicitly available
		*/
		Node<ElemType>* mthNodeFromEnd(int m);

		/*
		* Function : isCyclic()
		* ---------------------------------------
		* Checks if the linked list is cyclic
		* returns true if it is false otherwise
		* Uses time and space efficient algorithm 
		* in doing so
		*/
		bool isCyclic();
		/*
		* Function : printList()
		* --------------------------------------
		* Prints to the console each Node's data  
		* that is present in the Linked List.
		* Avoids printing the list if the list is 
		* cyclic thus preventing an infinite loop.
		*/
		void printList();
		/*
		* Function : size()
		* -----------------------------------
		* Returns the number of Nodes present
		* in the Linked List
		*/
		int size();

	private : 
		Node<ElemType> * head;
		Node<ElemType> * tail;
		int numNodes;
};

#endif


// Public routine implementations

template <typename ElemType>
LinkedList<ElemType>::LinkedList() {
	head = NULL;
	tail = NULL;
	numNodes = 0;	
}

template <typename ElemType>
void LinkedList<ElemType>::addAtBeginning(ElemType data) {
	Node<ElemType>* newMember = new Node<ElemType>(data, head);
	head = newMember;
	if(numNodes == 0) tail = head;
	// Comment out the following line of code if you don't want the list to be cyclic
	tail->setNext(head);
	numNodes++;
}

template <typename ElemType>
void LinkedList<ElemType>::printList() {
	if(isCyclic()) return; // avoid gettting into an infinite loop by printing a cyclic list
	Node<ElemType>* currNode = head;
	while(currNode->getNext() != NULL){
		std::cout<<currNode->getNodeData()<<" ";
		currNode = currNode->getNext();
	}
	std::cout<<currNode->getNodeData()<<std::endl;
}

template <typename ElemType>
int LinkedList<ElemType>::size() {
	return numNodes;
}


template <typename ElemType>
Node<ElemType>* LinkedList<ElemType>::mthNodeFromEnd(int m) {
	// Check if the list is empty
	Node<ElemType>* currNode = head;
	if(!currNode) return NULL;
	
	// Move the currNode pointer m times ahead in the list
	for(int i = 0 ;i < m;i++) {
		currNode = currNode->getNext();
		// what if there are less than m elements in the linked list in that case we will return null simply
		if(currNode == NULL) return NULL;
	}	

	Node<ElemType>* mStepsBehind = head;
	// now move the current node pointer to the end of the list also move the above pointer simultaneously with it
	while(currNode->getNext() != NULL) {
		currNode = currNode->getNext();
		mStepsBehind = mStepsBehind->getNext();
	}

	// once the traversal is over the mStepsBehind must be pointing to the mth from end Node
	return mStepsBehind;
}


template <typename ElemType>
bool LinkedList<ElemType>::isCyclic() {
	// you will need two node pointer here one fast and one slow pointer 
	// we will increment these pointers at different speeds
	Node<ElemType>* fastPointer;
	Node<ElemType>* slowPointer;
	// set the slowPointer to the head of the linked list
	slowPointer = head;
	// set the slowPointer ahead of the fastPointer
	fastPointer = head->getNext();

	// Now we will traverse the list 
	while(true) {
		// In a cyclic list no pointer will ever reach dead end 
		if(!fastPointer || !fastPointer->getNext())
			return false;
		else if(fastPointer == slowPointer || fastPointer->getNext() == slowPointer) {
			// the slow and the fast pointer will overalp in a cyclic list 
			return true;
		}else{
			// advance the two pointers ahead in the list
			slowPointer = slowPointer->getNext();
			fastPointer = fastPointer->getNext()->getNext();
		}

	}
}