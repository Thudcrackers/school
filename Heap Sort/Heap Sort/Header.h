#pragma once

#include <iostream>
#include <vector> 

using namespace std;

class Heap {
public:
	int heapSize;
	vector<int> v;

	//figures out the index of the left child
	int left(int i) {
		return (i * 2) + 1;
	}
	//figures out the index of the right child
	int right(int i) {
		return (i * 2) + 2;
	}
	
	void maxHeapify(int i) {
		//set the index of the left and right child, will be checked later
		int l = left(i);
		int r = right(i);
		//there is no largest yet, so the index is -1
		int largest = -1;
		//if the left child is not out of bounds and is greater than the current index, it becomes the new largest
		if (l < heapSize && v[l] > v[i]) {
			largest = l;
		}
		//if left child is not the largest, the current index is the largest
		else largest = i;
		//if right child is larger than largest, it becomes the new largest
		if (r < heapSize && v[r] > v[largest]) {
			largest = r;
		}
		//if the current index is not the largest, swap it with the largest
		if (largest != i) {
			int tmp = v[i];
			v[i] = v[largest];
			v[largest] = tmp;
			//call maxHeapify recursively
			maxHeapify(largest);
		}
	}

	void buildMaxHeap() {
		//max heapify the first half of the heap, the rest are leaves
		for (int i = heapSize / 2; i > 0; i--) {
			maxHeapify(i);
		}
	}

	void heapSort() {
		//build a max heap to put the largest element at the top
		buildMaxHeap();
		//work backwards and swap the root with the last element
		for (int i = heapSize - 1; i >= 1; i--) {
			int tmp = v[0];
			v[0] = v[i];
			v[i] = tmp;
			heapSize--;
			//max heapify to make sure the largest element is at the top
			maxHeapify(0);
		}
	}

	void printHeap() {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};