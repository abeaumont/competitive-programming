// https://open.kattis.com/problems/arrivingontime

#include <bits/stdc++.h>

using namespace std;

struct edge {
  int u, v, t0, p, d;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  vector<edge> edges(m);
  vector<vector<int>> g(n);
  vector<int> visited(n), d(n, -1);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].t0 >> edges[i].p >> edges[i].d;
    g[edges[i].v].push_back(i);
  }
  priority_queue<tuple<int, int>> q;
  q.push({s, n - 1});
  d[n - 1] = s;
  while (!q.empty()) {
    int t, v;
    tie(t, v) = q.top();
    q.pop();
    if (visited[v]) continue;
    visited[v] = 1;
    if (t < 0) {
      cout << "impossible\n";
      return 0;
    }
    if (!v) {
      cout << t << '\n';
      return 0;
    }
    for (int i : g[v]) {
      edge e = edges[i];
      if (!visited[e.u]) {
        int x = t - e.d;
        if (x < 0 || e.t0 > x) continue;
        int k = (x - e.t0) / e.p;
        x = e.t0 + k * e.p;
        if (x > d[e.u]) d[e.u] = x, q.push({x, e.u});
      }
    }
  }
  cout << "impossible\n";
}
