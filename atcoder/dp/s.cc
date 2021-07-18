// https://atcoder.jp/contests/dp/tasks/dp_s
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7, D = 100, K = 1e4;
ll dp[K + 1][D];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  int n, d;
  cin >> s >> d;
  n = s.size();
  for (int j = 1; j < 10; j++) dp[0][j % d] += 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 10; j++) {
      if (j) dp[i][j % d]++;
      for (int k = 0; k < d; k++) {
        int l = (k + j) % d;
        if (l < 0) l += d;
        (dp[i][l] += dp[i - 1][k]) %= M;
      }
    }
  ll ans = 0, acc = 0;
  for (int i = 0; i < n; i++) {
    int x = s[i] - '0';
    for (int j = 1; j <= x; j++)
      if ((acc + j) % d == 0) ans = (ans + 1) % M;
    for (int j = 0; j < x; j++)
      if (i < n - 1) {
        ll m = (d - acc - j) % d;
        if (m < 0) m += d;
        (ans += dp[n - i - 2][m]) %= M;
      }
    (acc += x) %= d;
  }
  cout << ans << '\n';
}
