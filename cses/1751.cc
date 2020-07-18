// https://cses.fi/problemset/task/1751
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi c, h;
vi a, b, g, s, t;

void dfs1(int i) {
  s[i] = 1;
  if (!s[g[i]])
    dfs1(g[i]);
  a.push_back(i);
}

void dfs2(int i) {
  t[i] = 1;
  b[i] = c.size() - 1;
  c.back().push_back(i);
  for (int j : h[i])
    if (!(t[j]))
      dfs2(j);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  g = vi(n), h = vvi(n);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    u--;
    g[i] = u;
    h[u].push_back(i);
  }
  s = vi(n);
  for (int i = 0; i < n; i++)
    if (!s[i])
      dfs1(i);
  b = vi(n);
  t = vi(n);
  for (int i = n - 1; i >= 0; i--)
    if (!t[a[i]]) {
      c.push_back(vi());
      dfs2(a[i]);
    }
  vi r(n);
  for (int i : a) {
    if (g[i] == i)
      r[i] = 1;
    else if (b[i] == b[g[i]])
      r[i] = c[b[i]].size();
    else
      r[i] = r[g[i]] + 1;
  }
  for (int i = 0; i < n; i++)
    cout << r[i] << " \n"[i == n - 1];
}
