#include <iostream>
#include "Header.h"

void main() {
	PriorityQueue myQ;			//create a Queue
	myQ.v = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };	//add elements

													/*****test with Jack's section to make sure it is correct*****/
	myQ.heapSize = myQ.v.size(); //have to set heapSize in order to use it
								 //printing the heap to compare it
	myQ.printHeap();
	//sort the heap
	myQ.heapSort();
	//print the sorted heap
	myQ.printHeap();

	myQ.heapSize = myQ.v.size();
	myQ.buildMaxHeap();
	//add elements to the queue
	myQ.insert(15);

	myQ.printHeap();

	////use the increaseKey() function
	myQ.increaseKey(8, 17);

	myQ.printHeap();

	////find maximum
	//myQ.extractMax();


}