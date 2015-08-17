/*
* File : LinkedList.c
* -----------------------
* Stores function delcarations for the LinkedList header files
* In the list the counting of nodes start from 0 like an array, and 
* not from 1.
* Author : Nishant Verma (Nash Vail) ( u14co041 )
*/

#include "LinkedList.h"
#include <stdlib.h>

int listLength(struct ListNode * head) {
	int numNodes = 0;
	struct ListNode * currentNode = head;
	while(currentNode != NULL) {
		numNodes++;
		currentNode = currentNode->next;
	}
	return numNodes;
}

void printList(struct ListNode * head) {
    if( head == NULL ) {
        printf("\n The list is empty \n");
        return;
    }
	struct ListNode * currentNode = head;
	while(currentNode != NULL) {
		printNodeData(currentNode);
		currentNode = currentNode->next;
	}
}

struct ListNode * getNodeAt(struct ListNode * head, int position) {

	if( isOutOfBounds(head, position) ) return NULL;

	int currentPosition = 0;
	struct ListNode * currentNode = head;
	while(currentPosition < position && currentNode != NULL) {
		currentNode = currentNode->next;
		currentPosition++;
	}

	return currentNode;
}

void insertAt(struct ListNode ** head, int data, int position) {
	if( *head == NULL ) {
		(*head) = getNewNode(data);
	} else if( position == 0 ) {
		struct ListNode * newNode = getNewNode(data);
		newNode->next = (*head);
		(*head) = newNode;
	} else {
		struct ListNode * newNode = getNewNode(data);
		// Node that will be present behind the new node in the list 
		struct ListNode * prevNode = getNodeAt(*head, position - 1); 
		if(prevNode == NULL) { // Invalid position passed
			printf("%s", "\nERROR : Invalid position passed!\n");
			return;
		}
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
}

void insertInBeginning(struct ListNode ** head, int data) {
	insertAt(head, data, 0);
}

void insertAtEnd(struct ListNode ** head, int data) {
	int lastPos = listLength(*head);
	insertAt(head, data, lastPos);
}

void insert(struct ListNode ** head, int data) {
	insertAtEnd(head, data);
}

void printNodeData(struct ListNode * node) {
	printf(" | %d |-> ", node->data);
}

struct ListNode * getNewNode(int data) {
	struct ListNode * newNode = (struct ListNode*)malloc( sizeof(struct ListNode) );
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

// Checking out of bounds over and over again is bad for efficiency, if this had been c++ we would have
// stored the length of the list implicitly in a variable and that way we wouldn't have to calculate it every time
int isOutOfBounds(struct ListNode * head, int position) {
	int length = listLength(head);
	if( position < 0 || position > length + 1 )  return 1;
	else return 0;
}

void deleteAt(struct ListNode ** head, int position) {
	if(*head == NULL) {
		printf("List is empty\n");
		return;
	}
    
    if( isOutOfBounds(*head, position) ) {
        printf("\nERROR : Invalid position passed for deletion");
        return;
    }
    
	if(position == 0) { // Delete the head node 
		struct ListNode * headAlias = *head;
		*head = (*head)->next;
		free(headAlias);
	} else {
        // In this case we will maintain a previous node while traversing the list
		struct ListNode * currentNode = (*head)->next;
		struct ListNode * prevNode = *head;

		int currentPosition = 1;

		while(currentPosition < position) {
			currentPosition++;
			currentNode = currentNode->next;
			prevNode = prevNode->next;
		}
		prevNode->next = currentNode->next;
		free(currentNode);
	}
}

void deleteInBeginning(struct ListNode ** head) {
    deleteAt(head, 0);
}

void deleteAtEnd(struct ListNode ** head) {
    int length = listLength(*head);
    deleteAt(head, length - 1);
}

void delete(struct ListNode ** head) {
    deleteAtEnd(head);
}

void deleteWholeList(struct ListNode ** head) {
    struct ListNode * tempNode, * currentNode;
    currentNode = *head;
    while(currentNode) {
        tempNode = currentNode->next;
        free(currentNode);
        currentNode = tempNode;
    }
    *head = NULL;
}