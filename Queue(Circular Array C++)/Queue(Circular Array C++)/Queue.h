//
//  Queue.h
//  Queue(Circular Array C++)
//
//  Created by Nash Vail on 08/09/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef Queue_Circular_Array_C____Queue_h
#define Queue_Circular_Array_C____Queue_h

template <typename el>
class Queue {
public:
    Queue();
    Queue(int queueCapacity);
    ~Queue();
    bool isEmpty();
    bool isFull();
    int size();
    void enqueue(el newElement);
    el dequeue();
private:
    int capacity;
    int front;
    int rear;
    el * elementsArray;
};


// Method implementations

template <typename el>
Queue<el>::Queue() {
    // We will give an arbitrary capcity of 10 elements
    capacity = 10;
    front = rear = -1;
    elementsArray = new el[capacity];
}

template <typename el>
Queue<el>::~Queue() {
    delete [] elementsArray;
}

template <typename el>
Queue<el>::Queue(int queueCapacity) {
    capacity = queueCapacity;
    front = rear = -1;
    elementsArray = new el[capacity];
}

template <typename el>
void Queue<el>::enqueue(el newElement) {
    if (isFull()) {
        std::cout<<"Sorry, looks like the queue is full."<<std::endl;
        return;
    } else if (isEmpty()) {
        front += 1;
        rear = front;
        elementsArray[front] = newElement;
    } else {
        rear = ( rear + 1 ) % capacity;
        elementsArray[rear] = newElement;
    }
}

template <typename el>
el Queue<el>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("The Queue is empty.");
    } else {
        el data = elementsArray[front];
        if (front == rear) { // There is just one element in the queue
            front = rear = -1;
        } else {
            front = ( front + 1 ) % capacity;
        }
        
        return data;
    }
}

template <typename el>
bool Queue<el>::isEmpty() {
    return (front == -1);
}

template <typename  el>
bool Queue<el>::isFull() {
    return ( (rear + 1) % capacity == front );
}

template <typename el>
int Queue<el>::size() {
    if (front == rear && front == -1) {
        return 0;
    }
    else return ( front > rear ? ( capacity - front + rear + 1 ) : ( rear - front + 1 ) );
}


#endif
