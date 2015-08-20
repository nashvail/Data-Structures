/*
* File : LinkedList.h
* ----------------------
* Stores structure and function definition and declaration respectively.
* Author : Nishant Verma (Nash Vail) ( u14co041 ) Aug, 11 2015
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Structure representing a single node in the linked list
typedef struct ListNode {
	int data;
	struct ListNode *next;
}Stack;

/*
* Function : printList(pointer to head node of the list)
* ---------------------------------------------------------
* Prints the data inside all of the nodes in the list 
*/
void printList(struct ListNode * head);

/*
* Function : printNodeData(pointer to node in the list)
* ---------------------------------------------------------
* Prints the dat inside the node is following style, if the 
* data is say 5 then it will be printed as 
* | 5 | > 
*/
void printNodeData(struct ListNode * node);

/*
* Function : isOutOfBounds(position)
* ---------------------------------------------------------
* Checks if the position passed in is out of bounds. An out 
* of bounds position is one which is either less than 0 or 
* greater than the last index of the node in the list.
*/
int isOutOfBounds(struct ListNode * head, int position);

/*
* Function : getNewNode(data that is to be associated with the new node)
* --------------------------------------------------------------------------
* Returns a new pointer to ListNode with data = data and next pointer = null
*/
struct ListNode * getNewNode(int data);

/*
* Function : listLength(pointer to head node of linked list)
* ----------------------------------------------------------
* Returns the number of nodes present in the linked list
*/
int listLength(struct ListNode * head);

/*
* Function : getNodeAt(pointer to head node, position from which node is to be retrieved)
* ---------------------------------------------------------------------------------------
* Returns node present at the passed in position, if the position is invalid i.e. out of
* bounds, NULL is returned.
*/
struct ListNode * getNodeAt(struct ListNode * head, int position);

/*
* Function : insertAt(double pointer to head node, data for new node, position to be inserted at)
* ----------------------------------------------------------------------------------------
* Inserts a new node at the passed in position, throws an error if the passed in position 
* if invalid.
*/
void insertAt(struct ListNode ** head, int data, int position);

/*
* Function : insertInBeginning(double pointer to head node, data for new Node)
* ----------------------------------------------------------------------------
*/
void insertInBeginning(struct ListNode ** head, int data);

/*
* Function : insertAtEnd(double pointer to head node, data for new Node)
* ----------------------------------------------------------------------------
*/
void insertAtEnd(struct ListNode ** head, int data);

/*
* Function : insert(double pointer to head node, data for new Node)
* ----------------------------------------------------------------------------
* An alias for insertAtEnd.
*/
void insert(struct ListNode ** head, int data);

/*
* Function : deleteAt(double pointer to head node, position at which the node is to be deleted)
* ----------------------------------------------------------------------------------------------
* Deletes the node present at position index in the list.
*/
void deleteAt(struct ListNode ** head, int position);

/*
* Function : deleteInBeginning(double pointer to head node of the list)
* ---------------------------------------------------------------------
*/
void deleteInBeginning(struct ListNode ** head);

/*
* Function : deleteAtEnd(double pointer to head node of the list)
* ---------------------------------------------------------------------
*/
void deleteAtEnd(struct ListNode ** head);
/*
* Function : delete(double pointer to head node of the list)
* ---------------------------------------------------------------------
* An alias for deleteAtEnd.
*/
void delete(struct ListNode ** head);

/*
* Function : deleteWholeList(double pointer to head node)
* -------------------------------------------------------
*/
void deleteWholeList(struct ListNode ** head);

#endif


