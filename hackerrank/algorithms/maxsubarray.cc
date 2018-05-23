// https://www.hackerrank.com/challenges/maxsubarray
#include <iostream>

using namespace std;

int a[100001];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int m = -10001;
		int M = -10001;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) m = max(0, m) + a[i];
			else if (m < 0) m = max(m, a[i]);
			c = max(c + a[i], a[i]);
			M = max(M, c);
		}
		cout << M << " " << m << endl;;
	}
}
