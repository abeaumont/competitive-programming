// http://codeforces.com/contest/954/problem/D
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> si;
typedef vector<int> vi;
typedef vector<si> vsi;
typedef tuple<int, int> ii;
typedef queue<ii> q;

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--;
	t--;
	vsi a(n);
	vi d(n, -1);
	vi e(n, -1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u - 1].insert(v - 1);
		a[v - 1].insert(u - 1);
	}
	q q;
	q.push(make_tuple(t, 0));
	while (!q.empty()) {
		int u, k;
		tie(u, k) = q.front();
		q.pop();
		if (d[u] != -1) continue;
		d[u] = k;
		for (auto v : a[u]) {
			if (d[v] != -1) continue;
			q.push(make_tuple(v, k + 1));
		}
	}
	q.push(make_tuple(s, 0));
	while (!q.empty()) {
		int u, k;
		tie(u, k) = q.front();
		q.pop();
		if (e[u] != -1) continue;
		e[u] = k;
		for (auto v : a[u]) {
			if (e[v] != -1) continue;
			q.push(make_tuple(v, k + 1));
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || a[i].count(j)) continue;
			if (d[i] + e[j] + 1 < d[s]) continue;
			if (d[j] + e[i] + 1 < d[s]) continue;
			c++;
		}
	}
	cout << c / 2 << endl;
}
