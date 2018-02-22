// https://open.kattis.com/problems/zamka
#include <iostream>

using namespace std;

int sum(int x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main() {
	int l, d, x, n, m;
	cin >> l >> d >> x;
	for (int i = l; i <= d; i++) {
		if (sum(i) == x) {
			n = i;
			break;
		}
	}
	for (int i = d; i >= l; i--) {
		if (sum(i) == x) {
			m = i;
			break;
		}
	}
	cout << n << endl << m << endl;
}
