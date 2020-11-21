// https://cses.fi/problemset/task/1696
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using qi = queue<int>;
using vii = vector<ii>;

const int N = 1002;

int n, m, l[N], p[N];
int g[N][N];

bool dfs(int u) {
  if (u == n + m + 1) {
    while (u) g[p[u]][u]--, g[u][p[u]]++, u = p[u];
    return 1;
  }
  for (int v = 0; v <= n + m + 1; v++)
    if (l[v] == l[u] + 1 && g[u][v]) {
      p[v] = u;
      if (dfs(v)) return 1;
    }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int k, u, v;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) g[0][i]++;
  for (int i = n + 1; i <= n + m; i++) g[i][n + m + 1]++;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    g[u][n + v]++;
  }
  while (1) {
    fill(l, l + n + m + 2, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == n + m + 1) break;
      q.pop();
      for (int v = 0; v <= n + m + 1; v++)
        if (l[v] < 0 && g[u][v]) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0))
      ;
  }
  vii e;
  for (int i = 1; i <= n; i++)
    for (int j = n + 1; j <= n + m; j++)
      if (g[j][i]) e.push_back({i, j});
  cout << e.size() << '\n';
  for (auto [u, v] : e) cout << u << ' ' << v - n << '\n';
}
