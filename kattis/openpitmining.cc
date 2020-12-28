// https://open.kattis.com/problems/openpitmining
#include <bits/stdc++.h>

using namespace std;
using qi = queue<int>;

const int N = 202, INF = N * N;
int n, l[N], p[N], g[N][N], c[N][N];

bool dfs(int u, int f) {
  if (u == n + 1) {
    while (u) {
      c[p[u]][u] -= f;
      c[u][p[u]] += f;
      u = p[u];
    }
    return 1;
  }
  for (int v = 0; v <= n + 1; v++)
    if (l[v] == l[u] + 1 && c[u][v] > 0) {
      p[v] = u;
      if (dfs(v, min(c[u][v], f))) return 1;
    }
  return 0;
}

void dfs2(int u) {
  l[u] = 1;
  for (int v = 0; v <= n + 1; v++)
    if (!l[v] && c[u][v] > 0) dfs2(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  int v, w, m, u, C = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v >> w >> m;
    v -= w;
    if (v > 0) c[0][i] = g[0][i] = v, C += v;
    else if (v < 0)
      c[i][n + 1] = g[i][n + 1] = -v;
    while (m--) cin >> u, c[u][i] = g[u][i] = INF;
  }
  while (1) {
    fill(l, l + n + 2, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == n + 1) break;
      q.pop();
      for (int v = 0; v <= n + 1; v++)
        if (l[v] < 0 && c[u][v] > 0) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0, INF))
      ;
  }
  fill(l, l + n + 2, 0);
  dfs2(0);
  int P = 0;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++)
      if (l[i] && !l[j]) P += g[i][j];
  cout << C - P << '\n';
}
