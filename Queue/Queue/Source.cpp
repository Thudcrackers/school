#include "Header.h"


void main() {
	ArrayQueue * myQ = new ArrayQueue();

	//add elements to the queue
	cout << "Adding 1" << endl;
	myQ->enqueue(1);
	cout << "Adding 2" << endl;
	myQ->enqueue(2);
	cout << "Adding 3" << endl;
	myQ->enqueue(3);
	cout << "Adding 4" << endl;
	myQ->enqueue(4);
	cout << "Adding 5" << endl;
	myQ->enqueue(5);

	myQ->print();

	//error testing
	cout << "Attempting to add 6" << endl;
	myQ->enqueue(6);	//try to enqueue an extra element
	myQ->print();

	cout << "Removed " << myQ->dequeue() << endl;
	cout << "Adding 6" << endl;
	myQ->enqueue(6);	//try again now that an element has been removed
	myQ->print();

	cout << "Removed " << myQ->dequeue() << endl;
	cout << "Removed " << myQ->dequeue() << endl;

	myQ->enqueue(7);
	cout << "Removed " << myQ->dequeue() << endl;
	myQ->print();

	delete myQ;
}