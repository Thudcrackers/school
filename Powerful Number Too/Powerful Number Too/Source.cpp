#include <iostream>
#include <string>
using namespace std;

bool isPrime(int);
bool isPowerful(int);

void main1() {
	int count = 0,
		num1,
		num2;
	cin >> num1 >> num2;

	if (num1 < num2 && num1 >= 0) {
		//will need to test each number between num1 and num2
		long long int temp = num1;
		while (temp <= num2) {
			if (isPowerful(temp)) {
				count++;
			}
			temp++;
		}
	}
	cout << count << " powerful number(s) are between " << num1 << " and " << num2 << endl;

	//system("pause");
}

bool isPrime(int n) {

	for (long long int i = 2; i < n; i++) {
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

bool isPowerful(int m) {
	bool cond1 = false;
	bool cond2 = false;

	for (long long int p = 1; p < m; p++) {
		if (isPrime(p)) {
			if (m % p == 0) {
				if ((m % (p*p) == 0))
					cond1 = true;
			}
		}
	}

	for (long long int i = 0; i < m; i++) {
		for (long long int j = 0; j < m; j++) {
			if (((i*i)*(j*j*j)) == m) {
				cond2 = true;
			}
		}
	}

	if (cond1 && cond2)
		return true;
	else
		return false;
}