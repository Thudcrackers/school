#include "StackHeader.h"

void main() {
	Stack<int> myStack(5);

	myStack.print();
	myStack.push(1);
	myStack.print();
	myStack.push(2);
	myStack.push(3);
	myStack.print();
}