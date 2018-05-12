#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> si;

void dfs(const vvi& g, si &s, vi &v, int i) {
	if (v[i]) return;
	v[i] = 1;
	s.insert(i);
	for (auto z:g[i]) dfs(g, s, v, z);
}

int main() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vvi g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vi v(n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (v[i]) continue;
		si s;
		dfs(g, s, v, i);
		for (auto z:s)
			if (s.count(a[z])) c++;
	}
	cout << c << endl;
}
