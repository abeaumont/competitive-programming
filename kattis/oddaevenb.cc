// https://open.kattis.com/problems/oddaevenb
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 100, M = 1e9 + 7;
ll dp[N + 1][4];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  dp[0][2] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
    dp[i][2] = dp[i - 1][3];
    dp[i][3] = dp[i - 1][1] + dp[i - 1][2];
    for (int j = 0; j < 4; j++)
      if (dp[i][j] >= M) dp[i][j] -= M;
  }
  cout << (dp[n][1] + dp[n][2]) % M << '\n';
}
