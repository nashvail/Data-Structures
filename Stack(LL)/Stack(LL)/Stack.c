//
//  Stack.c
//  Stack(LL)
//
//  Created by Nash Vail on 17/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.


#include "Stack.h"

Stack * createNewStack() {
    // Create a NULL linked list head node
    Stack * head = NULL;
    return head;
}

void push(Stack ** stack, int data) {
    insertInBeginning(stack, data);
}

int pop(Stack ** stack) {
    if(isUnderflowCondition(*stack)) {
        printf("\nERROR : cannot pop an empty stack\n");
        return -1; 
    }
    int topMostElementData = (*stack)->data;
    deleteInBeginning(stack);
    return topMostElementData;
}

int peek(Stack ** stack) {
    if (isUnderflowCondition(*stack)) {
        printf("\nTHE STACK IS EMPTY\n");
        return -1;
    }
    return (*stack)->data;
}

int isUnderflowCondition(Stack * stack) {
    return stack == NULL;
}

void deleteWholeStack(Stack ** stack) {
    deleteWholeList(stack);
}

int isEmpty(Stack * stack) {
    return isUnderflowCondition(stack);
}





