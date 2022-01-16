// https://codeforces.com/contest/1627/problem/C
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<vector<pair<int, int>>> g;
int e[N];
bool ok;

void dfs(int u, int p = -1, int v = 2) {
  if (g[u].size() > 2) {
    ok = 0;
    return;
  }
  for (auto it : g[u]) {
    if (it.first != p) {
      e[it.second] = v;
      if (v == 2) v = 5;
      else
        v = 2;
      dfs(it.first, u, v);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, u, v;
    cin >> n;
    g = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
    ok = 1;
    dfs(0);
    if (!ok) cout << "-1\n";
    else
      for (int i = 0; i < n - 1; i++) cout << e[i] << " \n"[i == n - 2];
  }
}
