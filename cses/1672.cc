// https://cses.fi/problemset/stats/1672
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, q, u, v, w;
  cin >> n >> m >> q;
  vvi d(n, vi(n, INF));
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w, u--, v--;
    if (w < d[u][v]) d[u][v] = d[v][u] = w;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
       for (int j = i + 1; j < n; j++)
         if (d[i][k] + d[k][j] < d[i][j])
           d[i][j] = d[j][i] = d[i][k] + d[k][j];
  while (q--) {
    cin >> u >> v, u--, v--;
    if (u == v) d[u][v] = 0;
    if (d[u][v] == INF) d[u][v] = -1;
    cout << d[u][v] << "\n";
  }
}
