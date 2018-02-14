// https://cses.fi/problemset/task/1143/
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<ii> sii;
typedef vector<sii> vsii;

int main() {
	int n, m, r, t;
	cin >> n >> m;
	r = sqrt(n);
	t = r * r == n ? r : r + 1;
	vii a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = make_tuple(x, i);
	}
	sort(a.begin(), a.end());
	vii l(t - 1);
	for (int i = 0; i < t - 1; i++) {
		l[i] = a[min((i + 1) * t, int(a.size() - 1))];
	}
	vsii b(r + 1);
	for (int i = 0; i < n; i++) {
		int k, x;
		tie(x, k) = a[i];
		int j = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
		b[j].insert(make_tuple(k, x));
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int s = lower_bound(l.begin(), l.end(), make_tuple(x, 0)) - l.begin();
		int o = n;
		int y;
		sii::iterator k;
		for (int j = s + 1; j < t; j++) {
			if (!b[j].size()) continue;
			int c, d;
			tie(c, d) = *b[j].begin();
			if (c < o) {
				o = c;
				y = j;
				k = b[j].begin();
			}
		}
		for (auto it = b[s].begin(); it != b[s].end(); it++) {
			int c, d;
			tie(c, d) = *it;
			if (c > o) break;
			if (c < o && d >= x) {
				o = c;
				y = s;
				k = it;
				break;
			}
		}
		if (o == n) {
			cout << 0;
		} else {
			int c, d;
			tie(c, d) = *k;
			cout << c + 1;
			b[y].erase(k);
			x = d - x;
			if (x) {
				int j = lower_bound(l.begin(), l.end(), make_tuple(x, c)) - l.begin();
				b[j].insert(make_tuple(c, x));
			}
		}
		if (i < m - 1) cout << " ";
	}
	cout << endl;
}
