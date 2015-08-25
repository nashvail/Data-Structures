//
//  Stack.h
//  Stack (Dynamic Array)
//
//  Created by Nash Vail on 24/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Stack__Dynamic_Array___Stack__
#define __Stack__Dynamic_Array___Stack__

#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArrayStack{
    int top;
    int capacity;
    int * array;
}Stack;

Stack * getNewStack();
int isEmpty(Stack * stack);
int isFull(Stack * stack);
void doubleStackCapacity(Stack * stack);
void push(Stack * stack, int data);
int pop(Stack * stack);
int peek(Stack * stack);
void deleteWholeStack(Stack * stack);


#endif /* defined(__Stack__Dynamic_Array___Stack__) */
