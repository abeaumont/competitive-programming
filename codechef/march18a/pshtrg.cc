// https://www.codechef.com/MARCH18A/problems/PSHTRG
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
	int n, q;
	cin >> n >> q;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int k = sqrt(n);
	int m = k * k < n ? (n + k - 1) / k : k;
	vvi b(m);
	for (int i = 0; i < m; i++) {
		vi c;
		for (int j = 0; j < k; j++) {
			if (i * k + j == n) break;
			c.push_back(a[i * k + j]);
		}
		sort(c.begin(), c.end(), greater<ll>());
		int j = 0;
		while (j < min(int(c.size()), 3)) b[i].push_back(c[j++]);
		while (j < c.size()) {
			if (c[j-1] + c[j-2] > c[j-3]) break;
			b[i].push_back(c[j++]);
		}
	}
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		l--;
		if (t == 1) {
			int o = a[l];
			int i = l / k;
			a[l] = r;
			if (o < b[i].back() && r < b[i].back()) continue;
			vi c;
			for (int j = 0; j < k; j++) {
				if (i * k + j == n) break;
				c.push_back(a[i * k + j]);
			}
			sort(c.begin(), c.end(), greater<ll>());
			b[i].clear();
			int j = 0;
			while (j < min(int(c.size()), 3)) b[i].push_back(c[j++]);
			while (j < c.size()) {
				if (c[j-1] + c[j-2] > c[j-3]) break;
				b[i].push_back(c[j++]);
			}
		} else {
			r--;
			vi c;
			int i = l / k;
			int ii = r / k;
			if ((r + 1) % k != 0) {
				if (ii > i)
					for (int j = ii * k; j <= r; j++) c.push_back(a[j]);
				ii--;
			}
			if (l % k != 0 || i > ii) {
				i++;
				for (int j = l; j < min(i * k, r + 1); j++) c.push_back(a[j]);
			}
			for (int j = i; j <= ii; j++)
				for (auto z : b[j]) c.push_back(z);
			sort(c.begin(), c.end(), greater<ll>());
			ll z = 0;
			if (c.size() >= 3) {
				int j = 2;
				while (j < c.size()) {
					if (c[j-1] + c[j] > c[j-2]) {
						z = c[j-2] + c[j-1] + c[j];
						break;
					}
					j++;
				}
			}
			cout << z << endl;
		}
	}
}
