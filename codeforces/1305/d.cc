// https://codeforces.com/contest/1305/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;
using vsi = vector<si>;
using qii = queue<ii>;

ll n;
vsi g;
si valid;

void dfs(int u, int p) {
  valid.erase(u);
  for (int v : g[u]) {
    if (v == p) continue;
    if (!valid.count(v)) continue;
    dfs(v, u);
  }
  g[u].clear();
}


ii nodes(int u) {
	qii q;
	si s;
	q.push({u, 0});
	s.insert(u);
	int a, k;
	while (!q.empty()) {
		tie(a, k) = q.front();
		q.pop();
		for (auto z : g[a]) {
			if (s.count(z)) continue;
			s.insert(z);
			q.push({z, k + 1});
		}
	}
	s.clear();
	q.push({a, 0});
	s.insert(a);
  vi d;
  int b;
	while (!q.empty()) {
		tie(b, k) = q.front();
		q.pop();
    d.push_back(b);
		for (auto z : g[b]) {
			if (s.count(z)) continue;
			s.insert(z);
			q.push({z, k + 1});
		}
	}
  return {a, d[k/2+1]};
}

int find(int u, int v, int p) {
  for (int k : g[u]) {
    if (k == v) return k;
    if (k == p) continue;
    int r = find(k, v, u);
    if (r != -1) return k;
  }
  return -1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll u, v;
  cin >> n;
  g = vsi(n);
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  valid = si();
  for (int i = 0; i < n; i++) valid.insert(i);
  while (valid.size() > 1) {
    int u = *valid.begin();
    int v, w;
    tie(u, v) = nodes(u);
    cout << "? " << u+1 << " " << v+1 << "\n";
    cout.flush();
    cin >> w;
    w--;
    if (w == u) {
      v = find(u, v, -1);
      dfs(v, u);
      g[u].erase(v);
    } else if (w == v) {
      u = find(v, u, -1);
      dfs(u, v);
      g[v].erase(u);
    } else {
      u = find(w, u, -1);
      dfs(u, w);
      g[w].erase(u);
      v = find(w, v, -1);
      dfs(v, w);
      g[w].erase(v);
    }
  }
  cout << "! " << (*valid.begin())+1 << "\n";
  cout.flush();
}
