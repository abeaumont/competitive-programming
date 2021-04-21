// https://open.kattis.com/problems/mincut
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using qi = queue<int>;
using vi = vector<int>;

const int N = 500;

int n, s, t, l[N], p[N];
ll g[N][N];
vi ans;

bool dfs(int u, ll c) {
  if (u == t) {
    while (u != s) g[p[u]][u] -= c, g[u][p[u]] += c, u = p[u];
    return 1;
  }
  for (int v = 0; v < n; v++)
    if (l[v] == l[u] + 1 && g[u][v]) {
      p[v] = u;
      if (dfs(v, min(c, g[u][v]))) return 1;
    }
  return 0;
}

void dfs2(int u) {
  l[u] = 1;
  ans.push_back(u);
  for (int v = 0; v < n; v++)
    if (!l[v] && g[u][v]) dfs2(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  ll c;
  cin >> n >> m >> s >> t;
  while (m--) cin >> u >> v >> c, g[u][v] += c;
  while (1) {
    fill(l, l + n, -1);
    qi q;
    q.push(s);
    l[s] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == t) break;
      q.pop();
      for (int v = 0; v < n; v++)
        if (l[v] < 0 && g[u][v]) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(s, 1e18))
      ;
  }
  fill(l, l + n, 0);
  dfs2(s);
  cout << ans.size() << '\n';
  for (int u : ans) cout << u << '\n';
}
