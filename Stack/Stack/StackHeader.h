#pragma once

#include <iostream>

using namespace std;

template <class T>
class Stack {
public:
	int size = 0;
	int capacity = 0;
	T* arr = new T[capacity];

	Stack(int cap) {
		capacity = cap * 2;
	}

	void push(T n) {
		if (size >= capacity) {
			capacity *= 2;
			T* tmparr = new T[capacity];
			for (int i = 0; i < size; i++) {
				tmparr[i] = arr[i];
			}
			arr = tmparr;
			delete tmparr;
		}
		arr[size] = n;
		size++;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};