// https://www.codechef.com/MARCH18A/problems/XXOR
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	int n, q;
	cin >> n >> q;
	vi a[31];
	for (int i = 0; i < 31; i++) a[i] = vi(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < 31; j++) {
			a[j][i] = a[j][i - 1];
			a[j][i] += bool(x & (1 << j));
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int u = (r - l + 2) / 2;
		int x = 0;
		for (int j = 0; j < 31; j++) {
			if (a[j][r] - a[j][l - 1] < u)
				x |= 1 << j;
		}
		cout << x << endl;
	}
}
