// https://atcoder.jp/contests/dp/tasks/dp_r
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 50;
const ll M = 1e9 + 7;
ll dp[60][N][N], ans[N][N], tmp[N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> dp[0][i][j];
  ll i = 1;
  for (; (1LL << i) <= k; i++)
    for (int u = 0; u < n; u++)
      for (int v = 0; v < n; v++)
        for (int w = 0; w < n; w++)
          (dp[i][u][w] += dp[i - 1][u][v] * dp[i - 1][v][w]) %= M;
  i--;
  for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++) ans[j][k] = dp[i][j][k];
  while (--i >= 0)
    if (k & (1ll << i)) {
      for (int i = 0; i < n; i++) fill(&tmp[i][0], &tmp[i][n], 0);
      for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
          for (int w = 0; w < n; w++)
            (tmp[u][w] += ans[u][v] * dp[i][v][w]) %= M;
      swap(ans, tmp);
    }
  ll s = 0;
  for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++) (s += ans[u][v]) %= M;
  cout << s << '\n';
}
