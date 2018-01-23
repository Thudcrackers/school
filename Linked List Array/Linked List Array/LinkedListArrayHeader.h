#pragma once
#include <iostream>

using namespace std;

class List {
public:
	static const int SIZE = 10;
	int list[SIZE];
	int head = 0;
	int tail = -3;

	void insert(int key) {
		tail += 3; //increases the tail to make room for the new element, next, and prev
		list[tail] = key; //set the current element to the key we are inserting
		list[tail + 1] = tail + 3; //set the next element to where it will be in the future
		if (tail != 0) //if tail != 0 is is not also the head, so we make sure prev is invalid
			list[tail + 2] = list[tail - 1];
		else //if the tail is not the head, set prev
			list[tail + 2] = -3;
	}

	void deleteItem(int key) {
		for (int i = 0; i <= tail; i + 3) {
			//if the item is found
			if (list[i] == key) {
				//if the current item is the head, set a new head
				if (i == head) {
					head = list[head + 1];
					break;
				}
				//set the next of the prev to the next of the current
				list[prev(i) + 1] = list[next(i)];
				//set the prev of the next to the prev of the current
				list[next(i) + 2] = list[prev(i)];
			}
		}
	}

	int next(int index) {
		return index + 1;
	}

	int prev(int index) {
		return index + 2;
	}

	void print() {
		for (int i = 0; i <= tail; i += 3) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
};