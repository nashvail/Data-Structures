//
//  main.c
//  Stack (Dynamic Array)
//
//  Created by Nash Vail on 24/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    
    Stack * intStack = getNewStack();
    push(intStack, 0);
    push(intStack, 10);
    push(intStack, 20);
    
    
    return 0;
}
