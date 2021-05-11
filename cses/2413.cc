// https://cses.fi/problemset/task/2413/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6;
const ll M = 1e9 + 7;
ll dp[N + 1][6];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  dp[0][1] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][4]) % M;
    dp[i][1] = dp[i][0];
    (dp[i][2] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] +
                dp[i - 1][5]) %= M;
    dp[i][5] = dp[i][4] = dp[i][3] = dp[i][2];
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (dp[n][1] + dp[n][4]) % M << '\n';
  }
}
