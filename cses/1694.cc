// https://cses.fi/problemset/task/1694/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using qi = queue<int>;

const int N = 500;

int n, l[N + 1], p[N + 1];
ll f, g[N + 1][N + 1];

bool dfs(int u, ll c) {
  if (u == n - 1) {
    f += c;
    while (u) {
      g[p[u]][u] -= c;
      g[u][p[u]] += c;
      u = p[u];
    }
    return 1;
  }
  for (int v = 0; v < n; v++)
    if (l[v] == l[u] + 1 && g[u][v] > 0) {
      p[v] = u;
      if (dfs(v, min(g[u][v], c))) return 1;
    }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  ll c;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    u--, v--;
    g[u][v] += c;
  }
  while (1) {
    fill(l, l + n, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == n - 1) break;
      q.pop();
      for (int v = 0; v < n; v++)
        if (l[v] < 0 && g[u][v] > 0) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0, 1e18))
      ;
  }
  cout << f << '\n';
}
