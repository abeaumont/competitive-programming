// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n>> m;
  vvi g(n);
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi p(n);
  qi q;
  q.push(0);
  p[0] = -1;
  while (!q.empty()) {
    u = q.front(); q.pop();
    if (u == n - 1) break;
    for(int v : g[u]) {
      if (!p[v]) {
        p[v] = u + 1;
        q.push(v);
      }
    }
  }
  if (!p[n - 1]) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vi r;
  u = n;
  while (u > 0) {
    r.push_back(u);
    u = p[u - 1];
  }
  cout << r.size() << "\n";
  for (int i = r.size() - 1; i >= 0; i--)
    cout << r[i] << " \n"[!i];
}
