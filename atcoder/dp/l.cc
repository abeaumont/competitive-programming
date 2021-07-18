// https://atcoder.jp/contests/dp/tasks/dp_l
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3000;
ll n, x[N], dp[N][N][2];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) dp[i][i][0] = x[i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j + i < n; j++)
      if (dp[j][j + i - 1][1] + x[j + i] > dp[j + 1][j + i][1] + x[j]) {
        dp[j][j + i][0] = dp[j][j + i - 1][1] + x[j + i];
        dp[j][j + i][1] = dp[j][j + i - 1][0];
      } else {
        dp[j][j + i][0] = dp[j + 1][j + i][1] + x[j];
        dp[j][j + i][1] = dp[j + 1][j + i][0];
      }
  cout << dp[0][n - 1][0] - dp[0][n - 1][1] << '\n';
}
