//
//  Stack.c
//  Stack (Array)
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include "Stack.h"

Stack * createStack(int capacity) {
    Stack * newStack = malloc( sizeof(struct ArrayStack) );
    if(!newStack)
        return NULL;
    
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->array = malloc( newStack->capacity * sizeof(int) );
    
    return newStack;
}


int isEmpty(Stack * stack) {
    return (stack->top == -1);
}

int isFull(Stack * stack) {
    return (stack->top == stack->capacity - 1);
}

void push(Stack * stack, int data) {
    if(isFull(stack))
        printf("Stack Overflow");
    else
        stack->array[++stack->top] = data;
}

int pop(Stack * stack) {
    if(isEmpty(stack)){
        printf("Stack Underflow");
        return 0;
    } else {
        return (stack->array[stack->top--]);
    }
}

void deleteWholeStack(Stack * stack) {
    if(stack) {
        if(stack->array) {
            free(stack->array);
        }
        free(stack);
    }
}

void peek(Stack * stack) {
    if(isEmpty(stack))
        printf("The stack is empty");
    else
        printf("\n%d\n", stack->array[stack->top]);
}

