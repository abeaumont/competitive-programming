// https://cses.fi/problemset/task/1673/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using iii = tuple<int, int, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using viii = vector<iii>;

const ll INF = 1e18;

void dfs(vvi &g, vi &s, int u) {
  s[u] = 1;
  for (int v:g[u])
    if (!s[v])
      dfs(g, s, v);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, u, v, w;
  cin >> n >> m;
  vvi g(n);
  vvi h(n);
  viii e(m);
  for(int i = 0; i < m ;i++) {
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(v);
    h[v].push_back(u);
    e[i] = {u, v, -w};
  }
  vi s(n), t(n);
  dfs(g, s, 0);
  dfs(h, t, n-1);
  vi d(n, INF);
  d[0] = 0;
  bool changed = 0;
  for (int i = 0; i < n; i++) {
    changed = false;
    for (iii x : e) {
      tie(u, v, w) = x;
      if (s[u] && t[v] && d[u] + w < d[v])
        changed = true, d[v] = d[u] + w;
    }
  }
  if (changed) cout << "-1\n";
  else cout << -d[n - 1] << "\n";
}
