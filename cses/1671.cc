// https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = tuple<ll, ll>;
using vii = vector<ii>;
using qii = priority_queue<ii, vii, greater<ii>>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, u, v, w, y;
  cin >> n >> m;
  vector<vii> g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
  }
  vector<ll> d(n, 1000000000LL * m + 1LL), s(n);
  d[0] = 0;
  qii q;
  q.push({0, 0});
  while (!q.empty()) {
    tie(w, u) = q.top();
    q.pop();
    if (s[u]) continue;
    s[u] = 1;
    for (ii x : g[u]) {
      tie(v, y) = x;
      if (d[u] + y < d[v]) {
        d[v] = d[u] + y;
        q.push({d[v], v});
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << d[i] << " \n"[i == n - 1];
}
