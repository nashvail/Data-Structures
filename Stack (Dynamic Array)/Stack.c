//
//  Stack.c
//  Stack (Dynamic Array)
//
//  Created by Nash Vail on 24/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include "Stack.h"

Stack * getNewStack() {
    Stack * newStack = (Stack*)malloc(sizeof(Stack));
    
    if (!newStack) {
        printf("\nERROR: Memory cannot be allocated");
        return NULL;
    }
    
    newStack->top = -1;
    newStack->capacity = 1; // Initially start with capacity of just 1 element
    newStack->array = malloc(sizeof(int));
    
    return newStack;
}

int isEmpty(Stack * stack) {
    return (stack->top == -1);
}

int isFull(Stack * stack) {
    return (stack->top == stack->capacity - 1);
}

void push(Stack * stack, int data) {
    if (isFull(stack)) {
        doubleStackCapacity(stack);
    }
    stack->array[++stack->top] = data;
}

int pop(Stack * stack) {
    if (isEmpty(stack)) {
        printf("\nThe stack is empty\n");
        return -1;
    } else {
        return (stack->array[stack->top--]);
    }
}

void doubleStackCapacity(Stack * stack) {
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity);
}

int peek(Stack * stack) {
    if (isEmpty(stack)) {
        printf("\nThe Stack is empty\n");
        return -1;
    } else {
        return (stack->array[stack->top]);
    }
}