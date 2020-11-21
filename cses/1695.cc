// https://cses.fi/problemset/task/1695/
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using qi = queue<int>;
using vii = vector<ii>;

const int N = 500;

int n, l[N + 1], p[N + 1];
int g[N + 1][N + 1];

bool dfs(int u) {
  if (u == n - 1) {
    while (u) g[p[u]][u]--, g[u][p[u]]++, u = p[u];
    return 1;
  }
  for (int v = 0; v < n; v++)
    if (l[v] == l[u] + 1 && g[u][v]) {
      p[v] = u;
      if (dfs(v)) return 1;
    }
  return 0;
}

void dfs2(int u) {
  l[u] = 1;
  for (int v = 0; v < n; v++)
    if (!l[v] && g[u][v]) dfs2(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u][v]++, g[v][u]++;
  }
  while (true) {
    fill(l, l + n, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == n - 1) break;
      q.pop();
      for (int v = 0; v < n; v++)
        if (l[v] < 0 && g[u][v]) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0))
      ;
  }
  fill(l, l + n, 0);
  dfs2(0);
  vii e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (l[i] && !l[j] && g[j][i]) e.push_back({i, j});
  cout << e.size() << '\n';
  for (auto [u, v] : e) cout << u + 1 << ' ' << v + 1 << '\n';
}
