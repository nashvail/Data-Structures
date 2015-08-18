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


extern int num_nodes;




#endif /* defined(__Circular_Linked_List__CLinkedList__) */
