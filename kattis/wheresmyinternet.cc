// https://open.kattis.com/problems/wheresmyinternet
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi s;

void dfs(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v])
      dfs(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  s = vi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int c = 0;
  for (int i = 0; i < n; i++)
    if (!s[i]) c++, cout << i+1 << '\n';
  if (!c) cout << "Connected\n";
}
