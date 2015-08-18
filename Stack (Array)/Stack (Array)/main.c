//
//  main.c
//  Stack (Array)
//
//  Created by Nash Vail on 18/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    Stack * intStack = createStack(2);
    push(intStack, 4);
    push(intStack, 10);
    peek(intStack);
    
    
    
    
    return 0;
}
