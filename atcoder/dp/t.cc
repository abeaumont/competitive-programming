// https://atcoder.jp/contests/dp/tasks/dp_t
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 3000, M = 1e9 + 7;
ll dp[N + 1][N + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  dp[1][1] = 1;
  for (int i = 1; i < n; i++)
    if (s[i - 1] == '<')
      for (int k = 1; k <= i + 1; k++)
        (dp[i + 1][k] = dp[i + 1][k - 1] + dp[i][k - 1]) %= M;
    else
      for (int k = 1; k <= i + 1; k++)
        (dp[i + 1][k] = dp[i + 1][k - 1] + dp[i][i] - dp[i][k - 1]) %= M;
  ll ans = dp[n][n];
  if (ans < 0) ans += M;
  cout << ans << '\n';
}
