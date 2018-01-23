#pragma once

#include <iostream>
using namespace std;

struct Node {
	Node * prev = NULL;	//default is NULL
	Node * next = NULL;	//default is NULL
	int key;
};

class DoublyLinkedList {
private:
	Node * head = NULL;
public:
	Node * listSearch(int k) {
		Node * nodeptr = head;

		//go through the list until k is found, or you reach the end
		while (nodeptr && nodeptr->key != k) {
			nodeptr = nodeptr->next;
		}
		//a value that is not in the list is considered invalid
		if (!nodeptr)
			throw "404 Error! Item not found!";
		//return the node pointer
		return nodeptr;
	}
	void listInsert(int k) {
		//create a new node with the value in the parameter
		Node * nodeptr = new Node;
		nodeptr->key = k;

		//assign the new node's next pointer
		nodeptr->next = head;

		//if the head is not null (list was not empty), then make that node point to our new node
		if (head)
			head->prev = nodeptr;
		else
			nodeptr->prev = NULL;

		head = nodeptr;

	}
	void listDelete(Node * nodeptr) {
		//if the node before this one is not null, point it to the next node (after the one being deleted)
		if (nodeptr->prev)
			nodeptr->prev->next = nodeptr->next;	//this still works if it is pointing to NULL
													//otherwise, assign it as the head
		else
			head = nodeptr->next;

		//if there is a node after this one, point it back to the one before the node being deleted
		if (nodeptr->next)
			nodeptr->next->prev = nodeptr->prev;

		//delete the node
		delete nodeptr;
	}
	void printList() {
		if (head) {
			Node * nodeptr = head;

			//go through the list until k is found, or you reach the end
			while (nodeptr) {
				cout << nodeptr->key << " ";
				nodeptr = nodeptr->next;
			}
			cout << endl;
		}
		else
			cout << "The list is empty!!" << endl;
	}
};