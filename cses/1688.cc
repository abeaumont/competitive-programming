// https://cses.fi/problemset/task/1688
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi a;
vvi g, t, d;

void dfs(int u, int p, int k) {
  a[u] = t[0].size();
  t[0].push_back(u + 1);
  d[0].push_back(k);
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, k + 1);
      t[0].push_back(u + 1);
      d[0].push_back(k);
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, u, v;
  cin >> n >> q;
  g = vvi(n);
  vi p(n);
  for (int i = 1; i < n; i++) {
    cin >> u;
    u--;
    p[i] = u;
    g[u].push_back(i);
    g[i].push_back(u);
  }
  int m = 2 * n - 1;
  int k = log2(m) + 1;
  a = vi(n);
  t = vvi(k);
  d = vvi(k);
  dfs(0, -1, 1);
  for (int i = 1, l = 2; i < k; i++, l *= 2) {
    d[i].resize(m - (l - 1));
    t[i].resize(m - (l - 1));
    for (int j = 0; j < m - (l - 1); j++)
      if (d[i - 1][j] <= d[i - 1][j + l / 2]) {
        d[i][j] = d[i - 1][j];
        t[i][j] = t[i - 1][j];
      } else {
        d[i][j] = d[i - 1][j + l / 2];
        t[i][j] = t[i - 1][j + l / 2];
      }
  }
  for (int i = 0; i < q; i++) {
    cin >> u >> v;
    u--, v--;
    u = a[u], v = a[v];
    if (u > v)
      swap(u, v);
    if (u == v) {
      cout << t[0][u] << '\n';
      continue;
    }
    int k = log2(v - u);
    int s = exp2(k);
    if (d[k][u] <= d[k][v - s + 1])
      cout << t[k][u] << '\n';
    else
      cout << t[k][v - s + 1] << '\n';
  }
}
