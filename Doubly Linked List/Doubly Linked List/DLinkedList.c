//
//  DLinkedList.c
//  Doubly Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include "DLinkedList.h"
#include <stdlib.h>

int list_size = 0;

void insertAt(struct DLLNode ** head, int data, int position) {
    if( isOutOfBounds(*head, position) ) {
        printf("\n ERROR : Invalid position Passed \n");
        return;
    }
    
    if (*head == NULL) {
        *head = getNewNode(data);
        list_size++;
    } else {
        
        struct DLLNode * prevNodeCurrentPos = getNodeAt(*head, position - 1);
        struct DLLNode * newNode = getNewNode(data);
        
        if ( isTailNode(prevNodeCurrentPos) ) { // Insertion at the end of the list
            newNode->prev = prevNodeCurrentPos;
            prevNodeCurrentPos->next = newNode;
        } else if (position == 0) { // Insertion at beginning of the list
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        } else { // Insertion in the middle of the list
            newNode->prev = prevNodeCurrentPos;
            newNode->next = prevNodeCurrentPos->next;
            
            prevNodeCurrentPos->next = newNode;
            (newNode->next)->prev = newNode;
        }
        
        list_size++;
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

void insertInBeginning(struct DLLNode ** head, int data) {
    insertAt(head, data, 0);
}

void insertAtEnd(struct DLLNode ** head, int data) {
    insertAt(head, data, list_size);
}

void insert(struct DLLNode ** head, int data) {
    insertAtEnd(head, data);
}

int isTailNode(struct DLLNode * node) {
    // You can't do something like return (node->next == NUL) in this bullshit language
    if (node->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isHeadNode(struct DLLNode * node) {
    if (node->prev == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isOutOfBounds(struct DLLNode * head, int position) {
    if(position < 0 || position > list_size + 1 ) return 1;
    else return 0;
}

void deleteAt(struct DLLNode ** head, int position) {
    if (*head == NULL || isOutOfBounds(*head, position)) {
        printf("\n ERROR: List empty or invalid position passed");
        return;
    }
    
    struct DLLNode * nodeToDelete = getNodeAt(*head, position);
    if (isTailNode(nodeToDelete)) { // Deletion at end
        (nodeToDelete->prev)->next = NULL;
        free(nodeToDelete);
    } else if(isHeadNode(nodeToDelete)) { // Deletion at the beginning
        struct DLLNode * headAlias = *head;
        *head = (*head)->next;
        free(headAlias);
    } else { // Deletion in the middle of the list
        (nodeToDelete->prev)->next = nodeToDelete->next;
        (nodeToDelete->next)->prev = nodeToDelete->prev;
        free(nodeToDelete);
    }
    
    list_size--;
}

void deleteInBeginning(struct DLLNode ** head) {
    deleteAt(head, 0);
}

void deleteAtEnd(struct DLLNode ** head) {
    deleteAt(head, list_size - 1);
}

void delete(struct DLLNode ** head) {
    deleteAtEnd(head);
}
