#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> lcsLength(string x, string y) {
	int m, n;

	if (x.length() > y.length()) {
		m = x.length();
		n = y.length();
	}
	else {
		m = y.length();
		n = x.length();
	}

	vector<vector<int>> b(m+1);
	vector<vector<int>> c(m+1);

	for (int j = 0; j <= m; j++) {
		for (int k = 0; k <= n; k++) {
			b[j].push_back(0);
			c[j].push_back(0);
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 2;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 3;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 1;
			}
		}
	}

	int length = c[m][n];
	cout << length << " ";
	return b;
}

void printLCS(vector<vector<int>> b, string x, int i, int j) {
	if (!i || !j)
		return;
	if (b[i][j] == 2) {
		printLCS(b, x, i - 1, j - 1);
		cout << x[i - 1];
	}
	else if (b[i][j] == 3)
		printLCS(b, x, i - 1, j);
	else
		printLCS(b, x, i, j - 1);
}