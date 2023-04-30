// https://cses.fi/problemset/task/1139
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5;
int d[N];
vector<int> g[N];
set<int> s[N];

void dfs(int u, int p) {
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      if (s[v].size() > s[u].size()) swap(s[u], s[v]);
    }
  for (int v : g[u])
    if (v != p)
      for (int x : s[v]) s[u].insert(x);
  d[u] = s[u].size();
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, u, v, x;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x, s[i].insert(x);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
}
