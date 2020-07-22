// https://cses.fi/problemset/task/1684
#include <bits/stdc++.h>

using namespace std;
using si = unordered_set<int>;
using vc = vector<char>;
using vi = vector<int>;
using vvi = vector<vi>;
using vsi = vector<si>;

vi a, b, s;
vvi c;
vsi g, h, p;

void dfs1(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v])
      dfs1(v);
  a.push_back(u);
}

void dfs2(int u) {
  s[u] = 1;
  b[u] = c.size() - 1;
  c.back().push_back(u);
  for (int v : h[u])
    if (!s[v])
      dfs2(v);
}

void dfs3(int u) {
  s[u] = 1;
  for (int v : p[u])
    if (!s[v])
      dfs3(v);
  a.push_back(u);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  char s1, s2;
  int n, m, u, v;
  cin >> n >> m;
  g = vsi(2 * m);
  h = vsi(2 * m);
  for (int i = 0; i < n; i++) {
    cin >> s1 >> u >> s2 >> v;
    u = (u - 1) * 2;
    v = (v - 1) * 2;
    if (s1 == '-' && s2 == '-') {
      g[u + 1].insert(v);
      g[v + 1].insert(u);
      h[v].insert(u + 1);
      h[u].insert(v + 1);
    } else if (s1 == '-' && s2 == '+') {
      g[u + 1].insert(v + 1);
      g[v].insert(u);
      h[v + 1].insert(u + 1);
      h[u].insert(v);
    } else if (s1 == '+' && s2 == '-') {
      g[u].insert(v);
      g[v + 1].insert(u + 1);
      h[v].insert(u);
      h[u + 1].insert(v + 1);
    } else if (s1 == '+' && s2 == '+') {
      g[u].insert(v + 1);
      g[v].insert(u + 1);
      h[v + 1].insert(u);
      h[u + 1].insert(v);
    }
  }
  s = vi(2 * m);
  for (int i = 0; i < 2 * m; i++)
    if (!s[i])
      dfs1(i);
  s = vi(2 * m);
  b = vi(2 * m);
  for (int i = 2 * m - 1; i >= 0; i--)
    if (!s[a[i]]) {
      c.push_back(vi());
      dfs2(a[i]);
    }
  for (int i = 0; i < m; i++)
    if (b[2 * i] == b[2 * i + 1]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  int k = c.size();
  p = vsi(k);
  for (int i = 0; i < 2 * m; i++) {
    u = b[i];
    for (int j : g[i]) {
      v = b[j];
      if (u != v)
        p[u].insert(v);
    }
  }
  s = vi(k);
  a = vi();
  for (int i = 0; i < k; i++)
    if (!s[i])
      dfs3(i);
  vc r(m);
  for (int i : a)
    for (int u : c[i])
      if (!r[u / 2])
        r[u / 2] = "-+"[u % 2];
  for (int i = 0; i < m; i++)
    cout << r[i] << " \n"[i == m - 1];
}
