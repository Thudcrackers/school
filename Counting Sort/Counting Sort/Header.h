#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Counting {
public:
	vector<int> unsorted, sorted;

	void countingSort() {
		vector<int> helper;
		int largest = 0;
		//looks through the unsorted vector for the largest element
		for (int i = 0; i < unsorted.size(); i++) {
			if (unsorted[i] > largest)
				largest = unsorted[i];
		}
		//sets the helper vector elements to 0
		for (int j = 0; j <= largest; j++) {
			helper.push_back(0);
		}
		//increments the position in the helper vector of the current number
		for (int k = 0; k < unsorted.size(); k++) {
			helper[unsorted[k]]++;
		}
		//finds the number of elements less than the one in each position
		for (int l = 0; l <= largest; l++) {
			if (l != 0)
				helper[l] = helper[l] + helper[l - 1];
		}
		//places each element in the correct sorted position
		sorted = unsorted; //set the vector to be sorted equal to unsorted, just to get them to the same size
		for (int m = unsorted.size() - 1; m >= 0; m--) {
			sorted[helper[unsorted[m]] - 1] = unsorted[m];
			helper[sorted[m]]--;
		}
	}

	void printUnsorted() {
		for (int i = 0; i < unsorted.size(); i++) {
			cout << unsorted[i] << " ";
		}
		cout << endl;
	}

	void printSorted() {
		for (int i = 0; i < sorted.size(); i++) {
			cout << sorted[i] << " ";
		}
		cout << endl;
	}
};