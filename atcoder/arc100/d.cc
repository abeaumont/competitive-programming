// https://atcoder.jp/contests/arc100/tasks/arc100_b
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a[200010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ll m = a[n];
	for (int i = 2; i <= n - 2; i++) {
		ll s1 = a[i], s2 = a[n] - a[i];
		ll m1 = (s1 - 1) / 2, m2 = (s2 - 1) / 2 + a[i];
		int j = lower_bound(a + 1, a + i, m1) - &a[1] + 1;
		ll d1 = a[j], d2 = a[i] - a[j];
		ll MM1 = max(d1, d2);
		ll mm1 = min(d1, d2);
		if (j > 1) {
			j--;
			d1 = a[j], d2 = a[i] - a[j];
			if (max(d1, d2) < MM1) {
				MM1 = max(d1, d2);
				mm1 = min(d1, d2);
			}
		}
		j = lower_bound(a + i + 1, a + n - 1, m2) - &a[i + 1] + 1;
		d1 = a[i + j] - a[i], d2 = a[n] - a[i + j];
		ll MM2 = max(d1, d2);
		ll mm2 = min(d1, d2);
		if (j > 1) {
			j--;
			d1 = a[i + j] - a[i], d2 = a[n] - a[i + j];
			if (max(d1, d2) < MM2) {
				MM2 = max(d1, d2);
				mm2 = min(d1, d2);
			}
		}
		m = min(m, max(MM1, MM2) - min(mm1, mm2));
	}
	cout << m << endl;
}
