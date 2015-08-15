//
//  main.c
//  Linked List
//
//  Created by Nash Vail on 15/08/15.
//  Copyright (c) 2015 Nash Vail. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

// Function Prototypes

int main(int argc, const char * argv[]) {
    struct ListNode * head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    printList(head);
    deleteWholeList(&head);
    printf("\n After the obliteration of the whole list\n");
    printList(head);
    
    return 0;
}
