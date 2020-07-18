// https://cses.fi/problemset/task/1682
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi g, h;
vi a, s, t;

void dfs1(int i) {
  s[i] = 1;
  for (int j : g[i])
    if (!s[j])
      dfs1(j);
  a.push_back(i);
}

void dfs2(int i) {
  t[i] = 1;
  for (int j : h[i])
    if (!(t[j]))
      dfs2(j);
}

int main() {
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
  t = vi(n);
  int c = 0;
  for (int i : a)
    if (!t[i]) {
      c++;
      if (c > 1) {
        cout << "NO\n" << i + 1 << ' ' << a[0] + 1 << '\n';
        return 0;
      }
      dfs2(i);
    }
  cout << "YES\n";
}
