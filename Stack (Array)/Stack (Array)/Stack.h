//
//  Stack.h
//  Stack (Array)
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Stack__Array___Stack__
#define __Stack__Array___Stack__

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
    int top;
    int capacity;
    int * array;
}Stack;

Stack * createStack(int capacity);
int isEmpty(Stack * stack);
int isFull(Stack * stack);
void push(Stack * stack, int data);
int pop(Stack * stack);
void peek(Stack * stack);
void deleteWholeStack(Stack * stack);

#endif /* defined(__Stack__Array___Stack__) */
