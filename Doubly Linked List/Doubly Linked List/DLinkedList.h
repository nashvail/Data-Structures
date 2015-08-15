//
//  DLinkedList.h
//  Doubly Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Doubly_Linked_List__DLinkedList__
#define __Doubly_Linked_List__DLinkedList__

#include <stdio.h>

// Structure representing a node in the Doubly Linked Lists
struct DLLNode {
    int data;
    struct DLLNode * next;
    struct DLLNode * prev;
};

void printNodeData(struct DLLNode * node);
void printList(struct DLLNode * head);
int listLength(struct DLLNode * head);
struct DLLNode * getNewNode(int data);
struct DLLNode * getNodeAt(struct DLLNode * head, int position);
void insertAt(struct DLLNode ** head, int data, int position);

#endif /* defined(__Doubly_Linked_List__DLinkedList__) */

