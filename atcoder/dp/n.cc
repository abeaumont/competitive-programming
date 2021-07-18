// https://atcoder.jp/contests/dp/tasks/dp_n
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 400;
const ll INF = (1ll << 62);
ll dp[N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      ll mn = INF;
      for (int k = 0; k < i; k++)
        mn = min(mn, dp[k][j] + dp[i - (k + 1)][j + k + 1]);
      dp[i][j] = mn + a[j + i + 1] - a[j];
    }
  }
  cout << dp[n - 1][0] << '\n';
}
