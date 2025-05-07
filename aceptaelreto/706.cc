// https://www.aceptaelreto.com/problem/statement.php?id=706
#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9;
int n;
vector<vector<pair<int, int>>> g;
vector<int> d;
vector<bool> p;
vector<tuple<int, int, int>> opt;

void sp() {
  d = vector<int>(n, INF);
  p = vector<bool>(n, 0);
  d[0] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (u == n - 1) break;
    if (p[u]) continue;
    p[u] = 1;
    for (auto x : g[u]) {
      int v = x.first, w = x.second;
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        q.push({-d[v], v});
      }
    }
  }
}

void dfs(int u) {
  if (p[u]) return;
  p[u] = 1;
  for (auto x : g[u]) {
    int v = x.first, w = x.second;
    if (d[v] + w == d[u]) {
      if (u < v) opt.emplace_back(u, v, w);
      else
        opt.emplace_back(v, u, w);
      dfs(v);
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int e, u, v, w;
  while (cin >> n >> e) {
    vector<tuple<int, int, int>> edges(e);
    g = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < e; i++) {
      cin >> u >> v >> w;
      u--, v--;
      if (u > v) swap(u, v);
      edges[i] = make_tuple(u, v, w);
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    sp();
    assert(d[n - 1] != INF);
    opt = vector<tuple<int, int, int>>();
    p = vector<bool>(n, 0);
    dfs(n - 1);
    sort(edges.begin(), edges.end());
    sort(opt.begin(), opt.end());
    g = vector<vector<pair<int, int>>>(n);
    int i = 0, j = 0;
    while (i < edges.size() && j < opt.size()) {
      if (edges[i] < opt[j]) {
        tie(u, v, w) = edges[i];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        i++;
      } else if (edges[i] == opt[j])
        i++, j++;
      else
        assert(false);
    }
    assert(j == opt.size());
    while (i < edges.size()) {
      tie(u, v, w) = edges[i];
      g[u].push_back({v, w});
      g[v].push_back({u, w});
      i++;
    }
    sp();
    if (d[n - 1] == INF) cout << "IMPOSIBLE\n";
    else
      cout << d[n - 1] << '\n';
  }
}
