// https://cses.fi/problemset/task/2134
#include <bits/stdc++.h>

using namespace std;
const int K = 18, N = 2e5;
int a[K][N], d[N], k, m[N], mi[N], s[N], ti[N], tk[N], x[N];
vector<int> g[N], t[N], y[N], z[N];

void dfs1(int u, int p) {
  d[u] = p < 0 ? 1 : d[p] + 1;
  s[u] = 1;
  a[0][u] = p;
  for (int v : g[u])
    if (v != p) dfs1(v, u), s[u] += s[v];
}

void dfs2(int u, int p, int i) {
  m[u] = i, mi[u] = ti[i]++;
  y[i].push_back(x[u]), z[i].push_back(u);
  int mx = 0, j;
  for (int v : g[u])
    if (v != p)
      if (s[v] > mx) mx = s[v], j = v;
  for (int v : g[u])
    if (v != p) {
      if (v == j) dfs2(v, u, i);
      else
        dfs2(v, u, k++);
    }
}

int lca(int u, int v) {
  if (d[v] > d[u]) swap(u, v);
  int b = d[u] - d[v];
  for (int i = 0; i < K; i++)
    if (b & (1 << i)) u = a[i][u];
  while (u != v) {
    int i = 0;
    while (a[i + 1][u] != a[i + 1][v]) i++;
    u = a[i][u], v = a[i][v];
  }
  return u;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, u, v, o;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs1(0, -1);
  for (int i = 1; i < K; i++)
    for (int j = 0; j < n; j++) a[i][j] = a[i - 1][a[i - 1][j]];
  dfs2(0, -1, k++);
  for (int i = 0; i < k; i++) {
    tk[i] = 1;
    while (tk[i] < ti[i]) tk[i] *= 2;
    t[i] = vector<int>(2 * tk[i]);
    for (int j = 0; j < y[i].size(); j++) t[i][tk[i] + j] = y[i][j];
    for (int j = tk[i] - 1; j; j--) t[i][j] = max(t[i][2 * j], t[i][2 * j + 1]);
  }
  for (int i = 0; i < n; i++) mi[i] += tk[m[i]];
  string sep = "";
  while (q--) {
    cin >> o >> u >> v;
    u--;
    if (o == 1) {
      t[m[u]][mi[u]] = v;
      for (int i = mi[u] / 2; i; i /= 2)
        t[m[u]][i] = max(t[m[u]][2 * i], t[m[u]][2 * i + 1]);
    } else {
      v--;
      int p = lca(u, v);
      int mx = 0, c = 0;
      for (int i = 0; i < 2; i++) {
        int x = i ? v : u;
        while (1) {
          c++;
          int l = m[x] == m[p] ? mi[p] : tk[m[x]], r = mi[x];
          while (l <= r) {
            if (l % 2 == 1) mx = max(mx, t[m[x]][l++]);
            if (r % 2 == 0) mx = max(mx, t[m[x]][r--]);
            l /= 2, r /= 2;
          }
          if (m[x] == m[p]) break;
          x = a[0][z[m[x]][0]];
        }
      }
      cout << sep << mx;
      if (sep.empty()) sep = " ";
    }
  }
  cout << '\n';
}
