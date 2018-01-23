#pragma once
#include <vector>
#include <climits>	//used for INT_MIN constant

//A priority queue is a data structure for maintaining a set S of elements, each with an associated value called a key.
using namespace std;

class PriorityQueue {
public:
	//declarations
	int heapSize = 0;
	vector<int> v;

	int maximum() {
		return v[0];
	}

	int extractMax() {
		if (heapSize < 0)
			cout << "ERROR: heap underflow" << endl;
		int max = v[0];
		v[0] = v[heapSize - 1];
		heapSize--;
		maxHeapify(0);
		return max;
	}

	void increaseKey(int i, int key) {
		if (key < v[i])
			cout << "ERROR: new key is smaller than current key." << endl;
		v[i] = key;
		while (i > 0 && v[i / 2] < v[i]) {
			int tmp = v[i];
			v[i] = v[i / 2];
			v[i / 2] = tmp;
			i = i / 2;
		}
	}

	void insert(int key) {
		heapSize++;
		v.push_back(INT_MIN);
		v[heapSize - 1] = INT_MIN;
		increaseKey(heapSize - 1, key);
	}

	/***************JACK'S CODE****************/

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
		for (int i = heapSize / 2; i >= 0; i--) {
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

////inserts the element x into the set v
//void insert(int k) {
//	heapSize++;
//	v.push_back(INT_MIN);
//	increaseKey(heapSize - 1, k);
//}
//
////returns the element of v with the largest key
//int maximum() {
//	return v[0];
//}
//
////removes and returns the element of v with the largest key
//int extractMax() {
//	//throw an error if empty
//	if (v.size() - 1 < 0)
//		throw "ERROR: heap underflow";
//
//	//otherwise store our maximum
//	int max = v[0];
//
//	//remove it from the queue
//	v[0] = v[heapSize - 1];
//	heapSize--;
//	maxHeapify(0);
//
//	//and return the max
//	return max;
//}
//
////increases the value of element x's key to the new value k
////note: k is assumed to be >= x's current key
//void increaseKey(int x, int k) {
//	//throw an error if new key is too small
//	if (k < v[x])
//		throw "Error: new key smaller than current key";
//
//	//otherwise increase the key
//	v[x] = k;
//	//parent = index/2
//	while (x>0 && v[(x / 2)] < v[x]) {
//		int temp = v[x];
//		v[x] = v[(x / 2)];
//		k = (x / 2);
//	}
//}
