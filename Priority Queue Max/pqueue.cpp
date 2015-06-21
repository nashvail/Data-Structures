/*
* File : pqueue.cpp
* ------------------
* Defines the internal mechanisms and working of 
* the Priority queue class
*/

#include "pqueue.h"
#include <iostream>

PQueue::PQueue(){
	//constructor function
}

PQueue::~PQueue(){
	//destructor function
}

/*
* Implementation notes : 
* -----------------------
* Adds the value to the queue making sure that the 
* largest of the values stay at top of the heap tree
* or in other words the tree always remains arranged in 
* decreasing order.
* The maintainance of arrangement is carried out by the 
* rearrangeAfterInsertion() function;
*/
void PQueue::enqueue(int value){
	rv.add(value);
	if(size() >= 2) rearrangeAfterInsertion();
}

	
//wrapper function FOR RecInsertRearrange() recursive function
void PQueue::rearrangeAfterInsertion(){
	recInsertRearrange(size());
}

void PQueue::recInsertRearrange(int endIndex){
	if(endIndex <= 1) return;
	if(rv.getAt(endIndex/2) >= rv.getAt(endIndex)) return;
	rv.swap(endIndex/2, endIndex);
	recInsertRearrange(endIndex/2);
}


/* Implementation notes: 
* ----------------------
* Removes the largest integer from the array ,which is the 
* one at the very begenning and returns it. After removal of 
* the element the heap is rearranged to make sure that 
* the arrangement of values is maintained in descending order.
* The maintainance of order of queue is managed by rearrangeAfterRemoval() 
* function.
* The algorithms says to remove the top most element from the queue
* and replace it with the last element/integer
* once done then trickle down the least value element placed at the top to
* the correct position.
*/
int PQueue::dequeueMax(){
	if(size() == 1) return (rv.removeAt(1));
	int max = rv.getAt(1);
	rv.swap(1,size());
	rv.removeAt(size());
	rearrangeAfterRemoval(); 
	return max;
}

//wrapper function for rearrangeAfterRemoval
void PQueue::rearrangeAfterRemoval(){
	recRemovalRearrange(1);
}

/*
* Implementation notes
* -----------------------
* Rearranges the whole heap to maintain it in order
* after an element is removed from the heap.
*/
void PQueue::recRemovalRearrange(int begIndex){
	if(hasNoMoreChildren(begIndex)) return;
	int largestChildIndex = largestChild(begIndex);
	if(rv.getAt(largestChildIndex) < rv.getAt(begIndex)) return;
	else{
		rv.swap(largestChildIndex, begIndex);
		recRemovalRearrange(largestChildIndex);
	}
}

//Private helper functions for recRemovalRearrange
bool PQueue::hasNoMoreChildren(int index){
	return((index * 2) > size() || index < 1);
}

int PQueue::largestChild(int index){
	//if an index has children then there are going to be atleast one 
	int firstChildIndex = index * 2;
	int secondChildIndex = ((firstChildIndex + 1) < size() ? firstChildIndex + 1 : -1);
	if(secondChildIndex == -1){
		return firstChildIndex;
	}else{
 		return((rv.getAt(firstChildIndex) > rv.getAt(secondChildIndex))? firstChildIndex : secondChildIndex);
	}
}

int PQueue::size(){
	return rv.size();
}
