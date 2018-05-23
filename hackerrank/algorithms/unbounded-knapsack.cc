// https://www.hackerrank.com/challenges/unbounded-knapsack
#include <iostream>

using namespace std;

int a[2000];
int c[2001];
int t, n, k;

int f(int b) {
	if (b == 0) return 0;
	if (c[b] != -1) return c[b];
	int m = b;
	for (int i = 0; i < n; i++) {
		int d = b - a[i];
		if (d >= 0) m = min(m, f(d));
	}
	c[b] = m;
	return m;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i <= k; i++) c[i] = -1;
		cout << k - f(k) << endl;
	}
}
