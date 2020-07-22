// https://cses.fi/problemset/task/1686
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using si = unordered_set<int>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vsi = vector<si>;

vvi g, h;
vsi p, q;
vb s;
vi a, b;
vl e;
int c;

void dfs1(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v])
      dfs1(v);
  a.push_back(u);
}

void dfs2(int u) {
  s[u] = 1;
  b[u] = c - 1;
  for (int v : h[u])
    if (!s[v])
      dfs2(v);
}

void dfs3(int u) {
  s[u] = 1;
  a.push_back(u);
  for (int v : p[u])
    if (!s[v])
      dfs3(v);
}

ll dfs4(int u) {
  s[u] = 1;
  ll mx = 0;
  for (int v : q[u]) {
    if (!s[v])
      dfs4(v);
    if (e[v] > mx)
      mx = e[v];
  }
  return e[u] += mx;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  vl d(n);
  for (int i = 0; i < n; i++)
    cin >> d[i];
  g = vvi(n);
  h = vvi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    h[v].push_back(u);
  }
  s = vb(n);
  for (int i = 0; i < n; i++)
    if (!s[i])
      dfs1(i);
  s = vb(n);
  b = vi(n);
  for (int i = n - 1; i >= 0; i--)
    if (!s[a[i]])
      c++, dfs2(a[i]);
  p = vsi(c);
  q = vsi(c);
  e = vl(c);
  for (int i = 0; i < n; i++) {
    u = b[i];
    e[u] += d[i];
    for (int j : g[i]) {
      v = b[j];
      if (u != v) {
        p[u].insert(v);
        q[v].insert(u);
      }
    }
  }
  a = vi();
  s = vb(c);
  for (int i = 0; i < c; i++)
    if (!s[i])
      dfs3(i);
  s = vb(c);
  for (int i : a)
    if (!s[i])
      dfs4(i);
  ll mx = 0;
  for (int i = 0; i < c; i++)
    if (e[i] > mx)
      mx = e[i];
  cout << mx << '\n';
}
