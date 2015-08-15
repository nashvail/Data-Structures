//
//  main.c
//  Doubly Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "DLinkedList.h"

int main(int argc, const char * argv[]) {
    struct DLLNode * head = NULL;
    insertAt(&head, 20, 0);
    insertAt(&head, 10, 0);
    insertAt(&head, 15, 1);
    printList(head);
    
    return 0;
}
