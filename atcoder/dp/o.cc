// https://atcoder.jp/contests/dp/tasks/dp_o
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int M = 1e9 + 7;
const int N = 21;
int g[N][N];
ll dp[1 << N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> g[i][j];
  dp[0] = 1;
  for (int s = 1; s < (1 << n); s++)
    for (int p = 0; p < n; p++)
      (dp[s] += dp[s ^ (1 << p)] * g[p][__builtin_popcount(s) - 1]) %= M;
  cout << dp[(1 << n) - 1] << '\n';
}
