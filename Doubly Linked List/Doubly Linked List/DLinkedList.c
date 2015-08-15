//
//  DLinkedList.c
//  Doubly Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include "DLinkedList.h"
#include <stdlib.h>

int listLength(struct DLLNode * head) {
    if ( head == NULL ) return 0;
    struct DLLNode * currentNode = head;
    int numNodes = 0;
    while (currentNode) {
        currentNode = currentNode->next;
        numNodes++;
    }
    
    return numNodes;
}

void insertAt(struct DLLNode ** head, int data, int position) {
    if (*head == NULL) {
        *head = getNewNode(data);
    } else if (position == 0) {
        struct DLLNode * newNode = getNewNode(data);
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        struct DLLNode * newNode = getNewNode(data);
        struct DLLNode * prevNode = getNodeAt(*head, position - 1);
        
        // Take care of the right side wiring
        newNode->next = prevNode->next;
        prevNode->next->prev = newNode;
        
        // Take care of the left side wiring
        prevNode->next = newNode;
        newNode->prev = prevNode;
        
        
    }
    
}

struct DLLNode * getNewNode(int data) {
    struct DLLNode * newNode = (struct DLLNode*)malloc( sizeof(struct DLLNode) );
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    
    return newNode;
}

struct DLLNode * getNodeAt(struct DLLNode * head, int position) {
    int currentPosition = 0;
    struct DLLNode * currentNode = head;
    
    while (currentPosition < position) {
        currentPosition++;
        currentNode = currentNode->next;
    }
    
    return currentNode;
    
}

void printList(struct DLLNode * head) {
    if( head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }
    
    struct DLLNode * currentNode = head;
    while(currentNode) {
        printNodeData(currentNode);
        currentNode = currentNode->next;
    }
}

void printNodeData(struct DLLNode * node) {
    printf(" =| %d |", node->data);
}