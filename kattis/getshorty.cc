// https://open.kattis.com/problems/getshorty

#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  double w;
  while (1) {
    cin >> n >> m;
    if (!n) break;
    vector<vector<tuple<int, double>>> g(n);
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    priority_queue<tuple<double, int>> q;
    q.push({1, 0});
    vector<bool> visited(n);
    vector<double> d(n);
    d[0] = 1;
    while (!q.empty()) {
      tie(w, u) = q.top();
      q.pop();
      if (visited[u]) continue;
      visited[u] = 1;
      if (u == n - 1) {
        cout << setprecision(4) << fixed << w << '\n';
        break;
      }
      for (auto [v, x] : g[u])
        if (d[v] < w * x) d[v] = w * x, q.push({d[v], v});
    }
  }
}
