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
		* Function : printList()
		* --------------------------------------
		* Prints to the console each Node's data  
		* that is present in the Linked List
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
		int numNodes;
};

#endif

// Public routine implementations

template <typename ElemType>
LinkedList<ElemType>::LinkedList() {
	head = NULL;
	numNodes = 0;	
}

template <typename ElemType>
void LinkedList<ElemType>::addAtBeginning(ElemType data) {
	if(numNodes == 0) {
		head = new Node<ElemType>(data);
	}else{
		Node<ElemType>* newMember = new Node<ElemType>(data, head);
		head = newMember;
	}
	numNodes++;
}

template <typename ElemType>
void LinkedList<ElemType>::printList() {
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