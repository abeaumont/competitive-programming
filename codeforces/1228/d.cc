// https://codeforces.com/contest/1228/problem/D
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;

vvi g;
vi c, r, s, t;
bool ok = 1;

void dfs(int u, int k) {
  r[u] = k;
  for (int v : g[u])
    if (!r[v]) dfs(v, k == 2 ? 3 : 2);
    else if (r[v] == k) ok = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  vii e(m);
  g = vvi(n);
  c = vi(6), r = vi(n), s = vi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    e[i] = {u, v};
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!s[i]) {
      s[i] = 1, r[i] = 1;
      for (int u : g[i]) s[u] = 2;
    }
  for (int i = 0; i < n; i++)
    if (!r[i])
      dfs(i, 2);
  vi x(4);
  for (int i = 0; i < n; i++)
    x[r[i]]++;
  for (int i = 1; i < 4; i++)
    if (!x[i]) ok = 0;
  if (ok) {
    for (ii x : e) {
      tie(u, v) = x;
      c[r[u] + r[v]]++;
    }
    if (x[1] * x[2] != c[3]) ok = 0;
    if (x[1] * x[3] != c[4]) ok = 0;
    if (x[2] * x[3] != c[5]) ok = 0;
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    cout << r[i] << " \n"[i == n - 1];
}
