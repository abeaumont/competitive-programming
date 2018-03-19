// https://open.kattis.com/problems/alicedigital
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vi a(n + 1, 0);
		int p = 0;
		int q = 0;
		int M = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] < m) {
					if (q) M = max(M, a[i - 1] - a[p]);
					p = i;
					q = 0;
			} else if (a[i] == m) {
				if (!q) q = i;
				else {
					M = max(M, a[i - 1] - a[p]);
					p = q;
					q = i;
				}
			}
			a[i] += a[i - 1];
		}
		if (q) M = max(M, a[n] - a[p]);
		cout << M << endl;
	}
}
