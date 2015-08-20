//
//  main.c
//  Stack(LL)
//
//  Created by Nash Vail on 17/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    
    Stack * myStack = createNewStack();
    push(&myStack, 42);
    push(&myStack, 13);
    push(&myStack, 17);
    
    deleteWholeStack(&myStack);
    
    
    while (!isEmpty(myStack)) {
        int currentElement = pop(&myStack);
        printf("%d\n", currentElement);
    }
    
    printf("That's all folks");
    
    return 0;
}
