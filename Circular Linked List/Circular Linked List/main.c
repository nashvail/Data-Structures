//
//  main.c
//  Circular Linked List
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "CLinkedList.h"

int main(int argc, const char * argv[]) {
    struct CLLNode * head = NULL;
    
    insertAt(&head, 24, 0);
    insertAt(&head, 25, 0);
    printList(head);
    
    
    return 0;
}
