#include <iostream>
#include <vector>

using namespace std;

void selectionSort(int list[], int size);

void main() {
	int tmp;
	const int size = 14;
	int list[size] = { 492, 118, 127, 144, 341, 20, 507, 557, 223, 72, 372, 2, 253, 532,};

	cout << "Unsorted: ";
	for (int i = 0; i < size; i++) {
		cout << list[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << endl;

	selectionSort(list, size);

	cout << "Sorted: ";
	for (int i = 0; i < size; i++) {
		cout << list[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

void selectionSort(int list[], int size) {
	int N = 0;
	while (N < size - 1) {
		int pos_min = N;
		int min = list[N];

		int pos_search = N;
		while (pos_search < size) {
			if (min>list[pos_search]) {
				min = list[pos_search];
				pos_min = pos_search;
			}
			pos_search = pos_search + 1;
		}
		int tmp = list[N];
		list[N] = list[pos_min];
		list[pos_min] = tmp;

		N = N + 1;
	}
}