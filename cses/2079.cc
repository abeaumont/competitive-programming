// https://cses.fi/problemset/task/2079
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5;
int n, d[N];
vector<int> g[N];

void dfs1(int u, int p) {
  d[u] = 1;
  for (int v : g[u])
    if (v != p) dfs1(v, u), d[u] += d[v];
}

int dfs2(int u, int p) {
  for (int v : g[u])
    if (v != p && d[v] > n / 2) return dfs2(v, u);
  return u;
}

int main() {
  cin.tie(0), ios::sync_with_stdio();
  int u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs1(0, -1);
  cout << dfs2(0, -1) + 1 << '\n';
}
