#pragma once

template<class T>

class LinkedList {
public:
	struct Node {
		T value;
		Node* next = NULL;
		Node* prev = NULL;
	};

	Node* head = NULL;
	Node* tail = NULL;

	bool isEmpty() {
		if (head == tail && tail == NULL)
			return true;
		else
			return false;
	}

	void printList() {
		if (isEmpty())
			cout << "ERROR: LIST IS EMPTY\n";
		else
			Node* current = head;
	}
};