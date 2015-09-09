//
//  Node.h
//  Stack (Array C++)
//
//  Created by Nash Vail on 05/09/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#ifndef __Stack__Array_C_____Node__
#define __Stack__Array_C_____Node__

#include <stdio.h>

template <typename ElemType>
class Node {
public:
    // default constructor function
    Node();
    // For when the data for the node is passe
    Node(ElemType nodeData);
    void setNext(Node<ElemType> * nextNode);
    // Gets the next node of the currentNode
    Node<ElemType> * getNextNode();
    
    ElemType getNodeData();
    
private:
    // The data that this node holds
    ElemType data;
    Node<ElemType> * next;
    
};

template <typename ElemType>
Node<ElemType>::Node(){
   // Just for the sake of the default constructor
}

template <typename ElemType>
Node<ElemType>::Node(ElemType nodeData){
    data = nodeData;
    next = NULL;
}

template <typename ElemType>
void Node<ElemType>::setNext(Node<ElemType> * nextNode) {
    next = nextNode;
}

template <typename ElemType>
Node<ElemType> * Node<ElemType>::getNextNode() {
    return next;
}

template <typename ElemType>
ElemType Node<ElemType>::getNodeData() {
    return data;
}



#endif /* defined(__Stack__Array_C_____Node__) */
