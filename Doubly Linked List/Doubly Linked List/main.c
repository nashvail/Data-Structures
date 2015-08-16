//
//  main.c
//  Doubly Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "DLinkedList.h"

// Function Prototypes

int main(int argc, const char * argv[]) {
    struct DLLNode * head = NULL;
    insert(&head, 0);
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    delete(&head);
    printList(head);
    
    return 0;
}


