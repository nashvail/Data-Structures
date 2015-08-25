//
//  main.c
//  Queue(Circular Array)
//
//  Created by Nash Vail on 25/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    Queue * intQueue = getNewQueue(5);
    
    
    enqueue(intQueue, 24);
    enqueue(intQueue, 25);
    enqueue(intQueue, 26);
    enqueue(intQueue, 27);
    
    
    int testData = dequeue(intQueue); // size = 4
    int size = getQueueSize(intQueue);
    printf("%d\n", size);
    testData = dequeue(intQueue); // size = 3
    testData = dequeue(intQueue); // size = 2
    printf("\n The data just taken out is %d\n", testData);
    
    
    return 0;
}
