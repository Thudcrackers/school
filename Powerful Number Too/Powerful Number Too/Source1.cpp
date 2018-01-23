#include <iostream>

using namespace std;

void main() {

	int com = 100000, x, m, k, z, count = 0;
	for (int l = 4; l < com; l++) {
		x = l;
		m = 3;
		k = 0;
		z = x;
		while (x % 2 == 0) {
			x /= 2;
			k += 1;
		}

		while ((m <= x) && (k != 1)) {
			k = 0;
			while (x % m == 0) {
				x /= m;
				k += 1;
			}
			m += 2;
		}

		if (k > 1)
			cout << z << ' '; count++;
	}
}