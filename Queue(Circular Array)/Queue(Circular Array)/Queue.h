//
//  Queue.h
//  Queue(Circular Array)
//
//  Created by Nash Vail on 25/08/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Queue_Circular_Array___Queue__
#define __Queue_Circular_Array___Queue__

#include <stdio.h>
#include <stdlib.h>

// Structure representing a single entry in the queue
typedef struct ArrayQueue {
    int front, rear;
    int capacity;
    int * array;
}Queue;

Queue * getNewQueue(int capacity);
int isEmpty(Queue * queue);
int isFull(Queue * queue);
int getQueueSize(Queue * queue);

void enqueue(Queue * queue, int data);
int dequeue(Queue * queue);

#endif /* defined(__Queue_Circular_Array___Queue__) */
