/*
* File : realvector.cpp
* ---------------------
* Defines the internal working and mechanism of Real Vector class 
*/

#include "realvector.h"
#include <iostream>

using namespace std;


/*
* Implementation notes : 
* -----------------------
* Initializes the pointer to integer by allocating space for 
* MAX_SIZE number of integers.
* Also sets the counter for number of integers in the array which
* is denoted by numUsed to 0
*/
RealVector::RealVector(){
	arr = new int[MAX_SIZE];
	numUsed = 0;
}

/*
* Implementation notes : 
* -------------------------
* Removes the dynamically allocated array from the heap
* when the array goes out of scope
*/

RealVector::~RealVector(){
	delete [] arr;
}

/*
* Implementation notes : 
* ----------------------
* The size of the array is same as the private var
* numUsed. Which is returned when this method is called.
*/
int RealVector::size(){
	return numUsed;
}

bool RealVector::isFilled(){
	return(size() == MAX_SIZE);
}

/*
* Implementation notes :
* ----------------------
* Swap takes in the real positions of the elements
* in the vector and swaps them.
* The passed in real positions are first converted to 
* actual positions before operating on them.
*/

void RealVector::swap(int realpos1, int realpos2){
	//we have to convert the passed in realPos to actual Pos
	if(!isInBounds(realpos1) && !isInBounds(realpos2)) return;

	int temp = arr[ActualIndex(realpos1)];
	arr[ActualIndex(realpos1)] = arr[ActualIndex(realpos2)];
	arr[ActualIndex(realpos2)] = temp;
}

/*
* Implementation notes : 
* -----------------------
* takes in the real index and converts that to actual
* before proceeding with the working of the function
*/

int RealVector::getAt(int realIndex){
	int ai = ActualIndex(realIndex);
	if(isInBounds(realIndex)){
		return(arr[ai]);
	}else{
		cout<<"Error: Out of bounds"<<endl;
		return (0);
	}
}


/*
* Implementation notes : 
* -----------------------
* add() method takes in an integer as it's parameter
* Before inserting the value at the end of the array
* it checks if the array is filled completely i.e 
* there are MAX_SIZE integers stored in the array
* If yes then a new array of double the current size is created
* using the doulbeCapacity() method, and the passed in value is added to it.
*/
void RealVector::add(int value){
	if(!isFilled()){
		arr[size()] = value;
		numUsed++;
	}else{
		doubleCapacity();
		arr[size()] = value;
		numUsed++;		
	}
}

/*
* Implementation notes : 
* ----------------------
* As more and more data is added into the array 
* and the number of elements reaches the maximum
* limit the array is expanded by doubling its capacity
*/

void RealVector::doubleCapacity(){
	int * bigger = new int[size() * 2];
	for(int i = 0 ; i < size() ; i++){
		bigger[i] = arr[i];
	}
	delete [] arr;
	arr = bigger;
}

int RealVector::removeAt(int realIndex){
	if(isInBounds(realIndex)){
		int actualindex = ActualIndex(realIndex);
		int value = arr[actualindex];
		for(int i = actualindex ; i < size();i++){
			arr[i] = arr[i+1];
		}
		numUsed--;
		return value;
	}else{
		cout<<"ERROR : Index out of bounds"<<endl;
		return -1;
	}
}

/* 
* Implementation notes:
* ---------------------
* Since the real vector uses a different way of counting 
* the elements inside it that is from 1 rather than 0
* this function helps in acheiving the same 
* when the value of realIndex is passed in it returns
* the actual index that could be used in the array to point
* at the correct specified location
* For example in RealVector the index of the very first element
* is 1 but in Actaul Array it is 0
* therefore when 1 is passed as real index, 0 is returned as actual
* index
*/

int RealVector::ActualIndex(int realIndex){
	return(realIndex - 1);
}

bool RealVector::isInBounds(int realindex){
	int ai = ActualIndex(realindex);// ai stands for actual index
	return(ai >= 0 && ai < size());
}