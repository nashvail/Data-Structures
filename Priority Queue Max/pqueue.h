/*
* File : pqueue.h
* ----------------
* Defines the interface for the Priority Queue(PQueue) class 
* The priority queue class is implemented by the Heap Binary tree
* The name choice here is important as though the implementation
* is done using a binary heap tree we abstract the ugly ans show
* the priority queue as a priority queue
*/

#ifndef PQUEUE_H
#define PQUEUE_H
#include "realvector.h"
	
class PQueue{
public:
	/*
	* Function : PQueue()
	* Usage    : Automatically Invoked
	* -----------------------------------------------------
	* Sets apart space for the input of integers	
	*/
	PQueue();
	/*
	* Function : ~PQueue
	* Usage    : Automatically Invoked
	* -----------------------------------------------------
	*/
	~PQueue();

	/*
	* Function : void enqueue(int value)
	* -----------------------------------------------------
	* Adds in the value passed as parameter to the queue
	* for later retreival.
	*/
	void enqueue(int value);

	/*
	* Function : size()
	* -----------------------------------------------------
	* Returns the number of elements or integers present in
	* the queue.
	*/
	int size();

	/*
	* Function : int dequeueMax()
	* -----------------------------------------------------
	* Returns the largest value present in the queue.
	*/
	int dequeueMax();
private:
	RealVector rv;
	int numElements;

	void rearrangeAfterInsertion();
	void recInsertRearrange(int endIndex);
	void rearrangeAfterRemoval();
	void recRemovalRearrange(int begIndex);
	int largestChild(int parentIndex);
	bool hasNoMoreChildren(int index);

};

#include "pqueue.cpp"

#endif
