#include "DoublyLinkedListHeader.h"
#include <iostream>
using namespace std;

void main() {
	DoublyLinkedList list;

	//add elements to the list
	list.listInsert(5);
	list.listInsert(4);
	list.listInsert(3);
	list.listInsert(2);
	list.listInsert(1);

	//print the list
	list.printList();

	//delete an element by first searching for it
	list.listDelete(list.listSearch(3));

	//print the list again
	list.printList();
}