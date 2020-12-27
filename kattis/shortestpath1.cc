// https://open.kattis.com/problems/shortestpath1
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using pq = priority_queue<ii, vii, greater<ii>>;

const int INF = 2e9;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  bool nl = 0;
  while (1) {
    int n, m, q, s, u, v, w;
    cin >> n >> m >> q >> s;
    if (!n) break;
    vvii g(n);
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      g[u].push_back({v, w});
    }
    pq pq;
    vi d(n, INF), vis(n);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      tie(w, u) = pq.top();
      pq.pop();
      vis[u] = 1;
      for (auto [v, w] : g[u])
        if (!vis[v] && d[u] + w < d[v]) d[v] = d[u] + w, pq.push({d[v], v});
    }
    if (nl) cout << '\n';
    else
      nl = 1;
    while (q--) {
      cin >> v;
      if (d[v] == INF) cout << "Impossible\n";
      else
        cout << d[v] << '\n';
    }
  }
}
