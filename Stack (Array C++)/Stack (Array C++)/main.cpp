//
//  main.cpp
//  Stack (Array C++)
//
//  Created by Nash Vail on 05/09/15.
//  Copyright (c) 2015 Nishant Verma ( Nash Vail ). All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;
int main(int argc, const char * argv[]) {
    
    // Let us make a new linked list
    LinkedList<int> l;
    l.insertAtBeginning(54);
    l.insertAtBeginning(44);
    l.print();
    
    return 0;
}
