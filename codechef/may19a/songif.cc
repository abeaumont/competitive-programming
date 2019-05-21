#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;

const ll INF = 9e18;

int n, j = 0;
vi d, h, m, p, r;
vvi g;

int dfs(int u) {
  int s = 1, m = 0;
  for (int v : g[u])
    if (v != p[u]) {
      p[v] = u, d[v] = d[u] + 1;
      int x = dfs(v);
      if (x > m) h[u] = v, m = x;
      s += x;
    }
  return s;
};

void decompose(int u, int w, int p) {
  r[u] = w, m[u] = j++;
  if (h[u] != -1) decompose(h[u], w, u);
  for (int v : g[u])
    if (v != p && v != h[u])
      decompose(v, v, u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, t, u, v;
  ll x, y, z;
  cin >> n >> q;
  vll k(n), b(n), l(n), c(n);
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  g = vvi(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  } 
  h = vi(n, -1), p = vi(n), d = vi(n), r = vi(n), m = vi(n);
  dfs(0);
  decompose(0, 0, -1);
  for (int i = 0; i < n; i++) l[m[i]] = k[i], c[m[i]] = b[i];
  for (int i = 0; i < q; i++) {
    cin >> t >> u >> v;
    u--, v--;
    if (t == 1) {
      cin >> x >> y;
      for (; r[u] != r[v]; v = p[r[v]]) {
        if (d[r[u]] > d[r[v]]) swap(u, v);
        for (int j = m[r[v]]; j <= m[v]; j++) l[j] += x, c[j] += y;
      }
      if (d[u] > d[v]) swap(u, v);
      for (int j = m[u]; j <= m[v]; j++)  l[j] += x, c[j] += y;
    } else {
      cin >> z;
      ll M = -INF;
      for (; r[u] != r[v]; v = p[r[v]]) {
        if (d[r[u]] > d[r[v]]) swap(u, v);
        for (int j = m[r[v]]; j <= m[v]; j++) M = max(M, l[j] * z + c[j]);
      }
      if (d[u] > d[v]) swap(u, v);
      for (int j = m[u]; j <= m[v]; j++) M = max(M, l[j] * z + c[j]);
      cout << M << "\n";
    }
  }
}
