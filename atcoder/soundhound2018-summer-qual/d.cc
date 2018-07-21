// https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_d
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef priority_queue<ii, vii, greater<ii>> pq;

ll n, m, s, t, u, v, a, b;

void bfs(vvii &g, vi& c, int s) {
	vb v(n);
	pq q;
	q.push(make_tuple(0, s));
	while (!q.empty()) {
		ll k, i;
		tie(k, i) = q.top();
		q.pop();
		if (v[i]) continue;
		v[i] = true;
		c[i] = k;
		for (auto &z:g[i]) {
			ll k2, i2;
			tie(k2, i2) = z;
			if (v[i2]) continue;
			q.push(make_tuple(k + k2, i2));
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	s--; t--;
	vvii ga(n), gb(n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> a >> b;
		u--; v--;
		ga[u].push_back(make_tuple(a, v));
		ga[v].push_back(make_tuple(a, u));
		gb[u].push_back(make_tuple(b, v));
		gb[v].push_back(make_tuple(b, u));
	}

	vi ca(n), cb(n), c(n);
	bfs(ga, ca, s);
	bfs(gb, cb, t);
	c[n - 1] = ca[n - 1] + cb[n - 1];
	for (int i = n - 2; i >= 0; i--) c[i] = min(c[i + 1], ca[i] + cb[i]);
	for (int i = 0; i < n; i++) cout << 1000000000000000LL - c[i] << endl;
}
