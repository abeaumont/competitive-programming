// https://abc087.contest.atcoder.jp/tasks/arc090_b
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unordered_set<ll> si;
typedef unordered_map<ll, ll> mii;

bool ok;

void dfs(const vvii &g, si &s, mii &c, int i) {
	if (!ok) return;
	for (auto z : g[i]) {
		ll j, d;
		tie(j, d) = z;
		if (c.find(j) != c.end()) {
			if (c[j] - c[i] != d) {
				ok = false;
				return;
			}
		} else c[j] = c[i] + d;
		auto it = s.find(j);
		if (it != s.end()) {
			s.erase(it);
			dfs(g, s, c, j);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vvii g(n);
	for (int i = 0; i < m; i++) {
		ll l, r, d;
		cin >> l >> r >> d;
		l--;
		r--;
		g[l].push_back(make_tuple(r, d));
		g[r].push_back(make_tuple(l, -d));
	}
	si s;
	for (int i = 0; i < n; i++) s.insert(i);
	ok = true;
	while (!s.empty()) {
		auto it = s.begin();
		s.erase(it);
		mii c;
		c[*it] = 0;
		dfs(g, s, c, *it);
	}
	cout << (ok ? "Yes\n" : "No\n");
}
