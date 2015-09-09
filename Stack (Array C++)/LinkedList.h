//
//  LinkedList.h
//  Stack (Array C++)
//
//  Created by Nash Vail on 05/09/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Stack__Array_C_____LinkedList__
#define __Stack__Array_C_____LinkedList__

#include <stdio.h>
#include <iostream>
#include "Node.h"

template <typename ElemType>
class LinkedList {
public:
    // Constructor function
    LinkedList();
    void insertAtBeginning(ElemType data);
    // Function that'll return the number of nodes in the linked list
    int size();
    // Function to print the whole list
    void print();
    
private:
    Node<ElemType> * head;
    Node<ElemType> * tail;
    int numNodes;
};

// Method definitions

template <typename ElemType>
LinkedList<ElemType>::LinkedList() {
    head = NULL;
    tail = NULL;
    numNodes = 0;
}

template <typename ElemType>
int LinkedList<ElemType>::size(){
    return numNodes;
}

template <typename ElemType>
void LinkedList<ElemType>::insertAtBeginning(ElemType data) {
    if (head == NULL) {
        head = new Node<ElemType>(data);
    } else {
        Node<ElemType> newNode = *new Node<ElemType>(data);
        newNode.setNext(head);
        head = &newNode;
    }
}


template <typename ElemType>
void LinkedList<ElemType>::print() {
    Node<ElemType> * currentNode = head;
    if (currentNode == NULL) {
        std::cout<<"The list is empty"<<std::endl;
    } else {
        while (currentNode) {
            std::cout<<currentNode->getNodeData()<<std::endl;
            currentNode = currentNode->getNextNode();
        }
    }
}




#endif /* defined(__Stack__Array_C_____LinkedList__) */
