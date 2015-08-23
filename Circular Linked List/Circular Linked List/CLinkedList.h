//
//  CLinkedList.h
//  Circular Linked List
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Circular_Linked_List__CLinkedList__
#define __Circular_Linked_List__CLinkedList__

#include <stdio.h>

// Structure that defines a single node in the circular linked list
struct CLLNode{
    int data;
    struct CLLNode * next;
};

void printList(struct CLLNode * head);
int listLength(struct CLLNode * head);

/*
* Function : getNewCircularNode(int data)
* ---------------------------------------
* Returns a new circular node with the data 
* associated with it equal to the one that is 
* passed as the argument. 
* A circular node is a node that has the next 
* pointer pointing to itself.
*/
struct CLLNode * getNewCircularNode(int data);

// Functions for insertion in the circular linked list
// General insert at cannot be used since this linked list is circular so .... or may be we can
void insertAt(struct CLLNode ** head, int data, int position);
// Insert at the end
// Insert in the beginning
// Insert at an intermediate position;



#endif /* defined(__Circular_Linked_List__CLinkedList__) */
