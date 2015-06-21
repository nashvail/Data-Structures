/*
* File : realvector.h
* -------------------
* Defines the interface for the Real Vector class
* A little about the Real Vector class : 
* Real vector is a higher version of a C++ array 
* the differnce is as you know uptil but the word 
* "real" suggests that unlike normal array or Vector 
* the counting of elements starts with 1 and not 0.
* Hence the names RealIndex and ActualIndex
* Which can be further represented as 
* ActualIndex = RealIndex - 1
*/

#ifndef REAL_VECTOR_H
#define REAL_VECTOR_H

class RealVector{
public:
	/*
	* Function : RealVector()
	* Usage    : Automatically Invoked
	* -----------------------------------------------------
	* This function acts as a constructor function for the 
	* RealVector class. Sets up the initial array for taking
	* in the data.
	*/
	RealVector();

	/*
	* Function : ~RealVector()
	* Usage    : Automatically Invoked
	* -----------------------------------------------------
	* Acts as a destructor function for the RealClass 
	* Vector. Destroys the data when object goes out of 
	* scope
	*/
	~RealVector();

	/*
	* Function : add(int value)
	* -----------------------------------------------------
	* Inserts the passed in value at the end of the array. Passed
	* in parameter should be an integer.
	*/

	void add(int value);

	/*
	* Function : int size()
	* -----------------------------------------------------
	* Returns the number of integers present in the array.
	*/
	int size();

	/*
	* Function : void swap(realpos1, realpos2)
	* -----------------------------------------------------
	* swap() as the name suggests swaps the values present in 
	* the array at indices of realpos1 and realpos2.
	* Passed in indices are "real indices" that is keeping in 
	* mind that the counting of elements in real vector starts
	* with 1 rather than 0 . Therefore the passed in positions
	* are accordingly adjusted.
	*/
	void swap(int realpos1, int realpos2);

	/*
	* Function : getAt(realIndex)
	* -----------------------------------------------------
	* Returns the value of integer present at the passed in 
	* "real index" parameter.Invokes an error when the passed in 
	* real index is out of bounds of the array.
	*/
	int getAt(int realindex);

	/*
	* Function : removeAt(int realindex)
	* -----------------------------------------------------
	* Takes in the real index or real position of the integer that is 
	* to be removed. Invokes an error when the passed in index
	* is out of bounds of the array .
	* Also returns the vlaue of integer that is removed from the array
	*/
	int removeAt(int index);
private:

	int * arr;
	const static int MAX_SIZE = 2;
	int numUsed;
	
	/*
	* Function : int ActualIndex()
	* Usage    : 
	* -----------------------------------------------------
	*/

	int ActualIndex(int realIndex);
	bool isFilled();
	void doubleCapacity();
	bool isInBounds(int realindex);

};

#include "realvector.cpp"

#endif

