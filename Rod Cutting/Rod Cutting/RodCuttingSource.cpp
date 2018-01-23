#include "RodCuttingHeader.h"
#include <fstream>

void main() {
	int n;
	vector<int> prices;

	ifstream inputFile;
	inputFile.open("table.txt");
	inputFile >> n;

	while (!inputFile.eof()) {
		int tmp;
		inputFile >> tmp;
		prices.push_back(tmp);
	}

	//cout << cutRod(prices, n) << endl;
	cout << memoizedCutRod(prices, n) << endl;
	//cout << bottomUpCutRod(prices, n) << endl;
}