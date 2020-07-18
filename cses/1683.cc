// https://cses.fi/problemset/task/1683
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c;
vvi g, h;
vi a, b, s, t;

void dfs1(int i) {
  s[i] = 1;
  for (int j : g[i])
    if (!s[j])
      dfs1(j);
  a.push_back(i);
}

void dfs2(int i) {
  t[i] = 1;
  b[i] = c;
  for (int j : h[i])
    if (!(t[j]))
      dfs2(j);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  h = vvi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    h[v].push_back(u);
  }
  s = vi(n);
  for (int i = 0; i < n; i++)
    if (!s[i])
      dfs1(i);
  reverse(a.begin(), a.end());
  b = vi(n);
  t = vi(n);
  for (int i : a)
    if (!t[i]) {
      c++;
      dfs2(i);
    }
  cout << c << '\n';
  for (int i = 0; i < n; i++)
    cout << b[i] << " \n"[i == n - 1];
}
