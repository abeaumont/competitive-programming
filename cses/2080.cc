#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5;
ll k, d[N], ans;
vector<int> g[N];
vector<vector<ll>> e;

void dfs(int u, int p, int i, int d) {
  if (e[0].size() == d) e[0].push_back(1);
  else
    e[0][d]++;
  if (e[i].size() == d) e[i].push_back(1);
  else
    e[i][d]++;
  if (d == k) return;
  for (int v : g[u])
    if (v != p) dfs(v, u, i, d + 1);
}

void dfs1(int u, int p) {
  d[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    if (g[v].empty()) {
      swap(g[u][i], g[u][g[u].size() - 1]);
      g[u].pop_back();
      if (i == g[u].size()) break;
      v = g[u][i];
    }
    dfs1(v, u), d[u] += d[v];
  }
}

int dfs2(int u, int p, int s) {
  for (int v : g[u])
    if (v != p && d[v] > s / 2) return dfs2(v, u, s);
  return u;
}

void centroid(int u) {
  dfs1(u, -1);
  int c = dfs2(u, -1, d[u]);
  if (g[c].empty()) return;
  e = vector<vector<ll>>(g[c].size() + 1, vector<ll>(1));
  for (int i = 1; i <= g[c].size(); i++) dfs(g[c][i - 1], c, i, 1);
  ll x = 0;
  for (int i = 1; i <= g[c].size(); i++) {
    if (e[i].size() > k) ans += e[i][k];
    for (int j = 1; j < e[i].size(); j++) {
      if (k - j >= e[0].size()) continue;
      ll m = e[0][k - j];
      if (k - j < e[i].size()) m -= e[i][k - j];
      x += e[i][j] * m;
    }
  }
  ans += x / 2;
  vector<int> next(g[c].size());
  for (int i = 0; i < g[c].size(); i++) next[i] = g[c][i];
  g[c].clear();
  for (int u : next) centroid(u);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, u, v;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  centroid(0);
  cout << ans << '\n';
}
