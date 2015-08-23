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

void insertAt(struct CLLNode ** head, int data, int position) {
    if (*head == NULL) { // If there is nothing in the list yet
        *head = getNewCircularNode(data);
        (*head)->next = *head;
    } else if (position == 0) { // For the insertion at beginning
        
        struct CLLNode * current = *head;
        struct CLLNode * newNode = getNewCircularNode(data);
        newNode->next = *head;
        
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        *head = newNode;
        
    } else { // For insertion at an intermediate position
        
    }
    
    // Insertion at the end will be taken care of later
}

struct CLLNode * getNewCircularNode(int data) {
    struct CLLNode * newNode = (struct CLLNode *) malloc(sizeof(struct CLLNode));
    
    newNode->data = data;
    newNode->next = newNode;
    
    return newNode;
}



