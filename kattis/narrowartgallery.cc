// https://open.kattis.com/problems/narrowartgallery
#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int a[N + 1][2], dp[N + 1][N + 1][3];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, k, sum = 0;
    cin >> n >> k;
    if (!n) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 2; j++) cin >> a[i][j], sum += a[i][j];
    for (int j = 0; j < 3; j++) dp[0][0][j] = 0;
    for (int i = 1; i <= k; i++)
      for (int j = 0; j < 3; j++) dp[0][i][j] = 2e9;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= k; j++) {
        dp[i][j][0] =
            min(dp[i - 1][j][0], min(dp[i - 1][j][1], dp[i - 1][j][2]));
        if (j) {
          dp[i][j][1] =
              min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + a[i - 1][0];
          dp[i][j][2] =
              min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + a[i - 1][1];
        }
      }
    cout << sum - min(dp[n][k][0], min(dp[n][k][1], dp[n][k][2])) << '\n';
  }
}
