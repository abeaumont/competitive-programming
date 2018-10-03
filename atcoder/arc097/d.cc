// https://arc097.contest.atcoder.jp/tasks/arc097_b
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi v;

void dfs(int u, int k) {
	v[u] = k;
	for (auto z:g[u]) {
    if (v[z]) continue;
    dfs(z, k);
  }
}

int main() {
	int n, m;
	cin >> n >> m;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	g = vvi(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	v = vi(n);
  int k = 1;
	for (int i = 0; i < n; i++) {
		if (v[i]) continue;
		dfs(i, k);
    k++;
	}
	int c = 0;
  for (int i = 0; i < n; i++) c += v[i] == v[a[i]];
	cout << c << endl;
}
