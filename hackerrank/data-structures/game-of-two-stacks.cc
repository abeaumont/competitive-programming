// https://www.hackerrank.com/challenges/game-of-two-stacks
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, x;
		cin >> n >> m >> x;
		vi a(n);
		vi b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		ll sum = 0;
		int i = 0;
		while (i < n && a[i] + sum <= x) sum += a[i++];
		int M = i;
		int j = 0;
		while (j < m) {
			if (b[j] + sum <= x) {
				sum += b[j++];
				M = max(M, i + j);
			} else if (i > 0) {
				sum -= a[--i];
			} else break;
		}
		cout << M << endl;
	}
}
