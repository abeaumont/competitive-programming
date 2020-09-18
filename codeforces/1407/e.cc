// https://codeforces.com/contest/1407/problem/E
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using qi = queue<int>;
using si = set<int>;
using misi = map<int, si>;
using graph = vector<misi>;

const int INF = 1000000;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v, t;
  cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> t;
    u--, v--;
    g[v][u].insert(t);
  }
  vi c(n);
  vi d(n, INF);
  vi s(n, 0);
  d[n - 1] = 0;
  qi q;
  q.push(n - 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == 0) break;
    vi todelete;
    for (auto [v, colors] : g[u]) {
      if (d[v] != INF) continue;
      if (s[v]) {
        for (int x : colors)
          if (x == c[v]) {
            d[v] = d[u] + 1;
            q.push(v);
          }
        todelete.push_back(v);
        continue;
      }
      if (colors.size() != 2) {
        todelete.push_back(v);
        c[v] = !*colors.begin();
        s[v] = 1;
      } else {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
    for (int v : todelete) g[u].erase(v);
  }
  if (d[0] == INF) cout << "-1\n";
  else
    cout << d[0] << '\n';
  for (int x : c) cout << x;
  cout << '\n';
}
