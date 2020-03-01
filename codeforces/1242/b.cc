// https://codeforces.com/contest/1242/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using si = set<int>;
using vsi = vector<si>;

int n;
si s;
vsi g;

void dfs(int u) {
  s.erase(u);
  vi q;
  for (int v : s)
    if (!g[u].count(v))
      q.push_back(v);
  for (int v : q)
    s.erase(v);
  for (int v : q)
    dfs(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  cin >> n >> m;
  g = vsi(n);
  s = si();
  for (int i = 0; i < n; i++) s.insert(i);
  for (int i = 0; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  int k = 0;
  while (!s.empty())
    k++, dfs(*s.begin());
  cout << k-1 << '\n';
}
