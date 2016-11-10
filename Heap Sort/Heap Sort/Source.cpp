#include "Header.h"

void main() {
	Heap h;
	h.v = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };

	h.heapSize = h.v.size(); //have to set heapSize in order to use it
	//printing the heap to compare it
	h.printHeap();
	//sort the heap
	h.heapSort();
	//print the sorted heap
	h.printHeap();
}