// https://www.codechef.com/MARCH18A/problems/GCDCNT
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> si;

vi primes;

void p(vi &a, int x) {
	int j = 0;
	while (x > 1) {
		int p = primes[j];
		if (!(x % p)) {
			a.push_back(p);
			x /= p;
			while (!(x % p)) x /= p;
		}
		j++;
	}
}

void s1(const vi &a, int i, si s[], int x, int k, bool e=false) {
	if (k == a.size()) {
		if (x > 1) {
			if (e) s[x].erase(i);
			else s[x].insert(i);
		}
		return;
	}
	s1(a, i, s, x, k + 1, e);
	s1(a, i, s, x * a[k], k + 1, e);
}

int s2(const vi &a, si s[], int x, int k, int j, int l, int r) {
	int c = 0;
	if (k == a.size()) {
		c = s[x].order_of_key(r + 1) - s[x].order_of_key(l);
		if (j % 2) return c;
		return -c;
	}
	c += s2(a, s, x, k + 1, j, l, r);
	c += s2(a, s, x * a[k], k + 1, j + 1, l, r);
	return c;
}

int main() {
	primes.push_back(2);
	for (int i = 3; i <= 100000; i++) {
		bool p = true;
		for (auto z : primes) {
			if (z * z > i) break;
			if (!(i % z)) {
				p = false;
				break;
			}
		}
		if (p) primes.push_back(i);
	}
	int ip[primes.back() + 1];
	for (int i = 0; i < primes.size(); i++) {
		ip[primes[i]] = i;
	}
	int n; cin >> n;
	si s[100001];
	vvi a = vvi(n);

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		p(a[i], x);
		s1(a[i], i + 1, s, 1, 0);
	}
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			x--;
			s1(a[x], x + 1, s, 1, 0, true);
			a[x].clear();
			p(a[x], y);
			s1(a[x], x + 1, s, 1, 0);
		} else {
			int l, r, g; cin >> l >> r >> g;
			vi v;
			p(v, g);
			cout << r - l + 1 - s2(v, s, 1, 0, 0, l, r) << endl;
		}
	}
}
