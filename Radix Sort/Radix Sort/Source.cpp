#include "Header.h"

void main() {
	Counting c;

	c.unsorted = { 2, 3, 1, 5, 4 };

	c.printUnsorted();

	c.countingSort();

	c.printSorted();
}