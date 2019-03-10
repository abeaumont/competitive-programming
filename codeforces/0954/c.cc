// http://codeforces.com/contest/954/problem/C
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll y = 0;
	bool ok = true;
	for (int i = 0; i < n - 1; i++) {
		ll x = abs(a[i] - a[i+1]);
		if (x == 0) { ok = false; break; }
		if (x == 1) continue;
		if (!y) { y = x; continue; }
		if (x != y) { ok = false; break; }
	}
	if (!y) y = 1;
	ll x = 0;
	if (ok) {
		for (int i = 0; i < n - 1; i++) {
			ll j1 = (a[i] - 1) % y;
			ll i1 = (a[i] - 1) / y + 1;
			ll j2 = (a[i + 1] - 1) % y;
			ll i2 = (a[i + 1] - 1) / y + 1;
			if (j1 == j2 && (i1 == i2 - 1 || i1 == i2 + 1)) {
				x = max(x, max(i1, i2));
				continue;
			}
			if (i1 == i2 && (j1 == j2 - 1 || j1 == j2 + 1)) {
				x = max(x, i1);
				continue;
			}
			ok = false;
			break;
		}
	}
	if (!x) x = a[0];
	if (ok && x >= 1 && x <= 1000000000 && y >= 1 && y <= 1000000000)
		cout << "YES\n" << x << " " << y << endl;
	else cout << "NO\n";
}
