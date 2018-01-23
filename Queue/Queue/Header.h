#pragma once
#include <iostream>
using namespace std;

//this operates on FIFO, like standing in a line
class ArrayQueue {
private:
	const int SIZE = 5;			//size declared here for simplicity
	int head, tail;				//used to keep track of beginning and end
	int Q[5];					//this array will act as our circular queue
	bool isEmpty = true, isFull = false;
public:
	ArrayQueue() {
		head = 0;
		tail = 0;
	}

	void enqueue(int element) {
		//new element is added to the tail of the queue
		if (isFull)
			cout << "Error! Queue is full." << endl;
		else {
			Q[tail] = element;

			//circular array - move tail to beginning if at the end
			if (tail == SIZE - 1)
				tail = 0;
			else //otherwise, just increment the tail
				tail++;

			if (tail == SIZE)
				tail = 0;
			if (head == tail)
				isFull = true;
		}
	}

	int dequeue() {
		//if the queue is empty, throw an error
		if (isEmpty)
			cout << "Error! Queue is empty!" << endl;
		else {
			//otherwise, store the element
			int element = Q[head];

			//and increase head to "remove" it
			if (head == SIZE - 1)
				head = 0;
			else
				head++;

			if (head == tail)
				isEmpty = true;

			//return the element that is removed from the queue
			return element;
		}
	}

	void print() {
		for (int i = 0; i < SIZE; i++) {
			cout << Q[i] << " ";
		}
		cout << endl;
	}

};