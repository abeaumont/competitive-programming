// https://open.kattis.com/problems/maxflow
#include <bits/stdc++.h>

using namespace std;

using qi = queue<int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, s, t, u, v, w;
  cin >> n >> m >> s >> t;
  vvi c(n, vi(n)), r(n, vi(n)), g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    c[u][v] += w;
    r[u][v] += w;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int mf = 0;
  while (1) {
    vi p(n, -1);
    qi q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      if (u == t) break;
      q.pop();
      for (int v : g[u]) {
        if (v != s && p[v] < 0 && r[u][v]) {
          p[v] = u;
          q.push(v);
        }
      }
    }
    if (q.empty()) break;
    int f = 1000000000;
    for (int v = t, u = p[v]; v != s; v = u, u = p[v])
      if (r[u][v] < f) f = r[u][v];
    mf += f;
    for (int v = t, u = p[v]; v != s; v = u, u = p[v])
      r[u][v] -= f, r[v][u] += f;
  }
  int e = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) e += c[i][j] > r[i][j];
  cout << n << ' ' << mf << ' ' << e << '\n';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (c[i][j] > r[i][j])
        cout << i << ' ' << j << ' ' << c[i][j] - r[i][j] << '\n';
}
