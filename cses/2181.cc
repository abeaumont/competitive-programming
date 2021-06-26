// // https://cses.fi/problemset/task/2181
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
const ll N = 1024;
ll dp[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < (1 << n); j++) {
      int x = ((1 << n) - 1) ^ j;
      int k = 0;
      do {
        int c = 0, ok = 1, jk = j ^ k;
        if ((n - __builtin_popcount(jk)) % 2) continue;
        for (int l = 0; l < n; l++) {
          if (!(j & (1 << l)) && !(k & (1 << l))) c++;
          else if (c % 2) {
            ok = 0;
            break;
          } else {
            c = 0;
          }
        }
        if (c % 2) ok = 0;
        if (ok) {
          dp[i][j] += dp[i - 1][k];
          if (dp[i][j] >= M) dp[i][j] -= M;
        }
      } while ((k = (k - x) & x));
    }
  cout << dp[m][0] << '\n';
}
