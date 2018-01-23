#pragma once

#include <iostream>
#include <vector>

using namespace std;

int max(int q, int w) {
	return (q < w) ? w : q;
}

int cutRod(vector<int> prices, int n) {
	if (n == 0)
		return 0;
	else {
		int q = -1;
		for (int i = 1; i <= n; i++) {
			q = max(q, (prices[i - 1] + cutRod(prices, n - i)));
		}
		return q;
	}
}

int memoizedCutRodAux(vector<int> prices, int n, int* arr) {
	int q;
	if (arr[n] >= 0)
		return arr[n];
	if (n == 0)
		q = 0;
	else {
		q = -1;
		for (int i = 1; i < n; i++)
			q = max(q, prices[i] + memoizedCutRodAux(prices, n - i - 1, arr));
	}
	arr[n] = q;
	return q;
}

int memoizedCutRod(vector<int> prices, int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = -1;

	return memoizedCutRodAux(prices, n, arr);
}

int bottomUpCutRod(vector<int> prices, int n) {
	int* arr = new int[n];
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		int q = -1;
		for (int j = 1; j <= i; j++) {
			q = max(q, prices[j] + arr[i - j - 1]);
		}
		arr[i] = q;
	}
	return arr[n];
}