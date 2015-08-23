//
//  Stack.h
//  Stack(LL)
//
//  Created by Nash Vail on 17/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Stack_LL___Stack__
#define __Stack_LL___Stack__

#include <stdio.h>
#include "LinkedList.h"

Stack * createNewStack();
int isUnderflowCondition(Stack * stack);
void push(Stack ** stack ,int data);
int pop(Stack ** stack);
int peek(Stack ** stack);
int isEmpty(Stack * stack);
// Removes all the elements from the stack
void deleteWholeStack(Stack ** stack);

#endif /* defined(__Stack_LL___Stack__) */
