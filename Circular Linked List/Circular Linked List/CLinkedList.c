//
//  CLinkedList.c
//  Circular Linked List
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


void printList(struct CLLNode * head) {
    struct CLLNode * current = head;
    
    if (head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }
    
    do{
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);
    
    printf("\n");
    
}

// Returns the number of unique nodes in the circular linked list
int listLength(struct CLLNode * head) {
    struct CLLNode * current = head;
    int count = 0;
    
    if(head == NULL) return 0;
    
    do{
        current = current->next;
        count++;
    } while(current != head);
    
    return count;
}

void insertInBeginning(struct CLLNode ** head, int data) {
    struct CLLNode * newNode = getNewCircularNode(data);
    
    if( *head == NULL ) {
        *head = newNode;
        return;
    } else {
        newNode->next = *head;
        
        struct CLLNode * currentNode = *head;
        while(currentNode->next != *head ){
            currentNode = currentNode->next;
        }
        
        currentNode->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct CLLNode ** head, int data) {
    struct CLLNode * newNode = getNewCircularNode(data);
    struct CLLNode * currentNode = *head;
    
    while (currentNode->next != *head) {
        currentNode = currentNode->next;
    }
    
    newNode->next = *head;
    currentNode->next = newNode;
    
}

struct CLLNode * getNewCircularNode(int data) {
    struct CLLNode * newNode = (struct CLLNode *) malloc(sizeof(struct CLLNode));
    
    newNode->data = data;
    newNode->next = newNode;
    
    return newNode;
}

void deleteAtEnd(struct CLLNode ** head) {
    // Create two pointers and progress them one by one, while keeping one behind the other
    struct CLLNode * oneBehindCurrent = *head, *current = *head;
    if(*head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }
    
    while(current->next != *head) {
        oneBehindCurrent = current;
        current = current->next;
    }
    
    oneBehindCurrent->next = current->next;
    free(current);
}

void deleteInBeginning(struct CLLNode ** head) {
    // Create a temporary node alias for the head node
    struct CLLNode * headAlias = *head;
    struct CLLNode * currentNode = *head;
    
    // Loop through and grab the tail pointer
    while (currentNode->next != *head) {
        currentNode = currentNode->next;
    }
    
    currentNode->next = (*head)->next;
    *head = (*head)->next;
    free(headAlias);
}



