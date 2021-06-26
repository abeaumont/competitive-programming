// https://cses.fi/problemset/task/1690
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 20;
const ll M = 1e9 + 7;
ll dp[1 << N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    g[b].push_back(a);
  }
  dp[1][0] = 1;
  for (int s = 1; s < (1 << n); s += 2)
    for (int x = 0; x < n; x++)
      if (s & (1 << x))
        for (int u : g[x])
          if (s & (1 << u)) {
            dp[s][x] += dp[s ^ (1 << x)][u];
            if (dp[s][x] > M) dp[s][x] -= M;
          }
  cout << dp[(1 << n) - 1][n - 1] << '\n';
}
