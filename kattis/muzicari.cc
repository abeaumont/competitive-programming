// https://open.kattis.com/problems/muzicari
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int t, n;
  cin >> t >> n;
  vi a(n), r(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vvi dp(t+1, vi(n+1));
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j-1];
      int w = a[j-1];
      if (i >= w) dp[i][j] = max(dp[i][j], w+dp[i-w][j-1]);
    }
  }
  int w = t;
  for (int i = n; i>= 1; i--) 
    if (dp[w][i-1] != dp[w][i]) {
      w -= a[i-1];
      r[i-1] = 1;
    }
  int t1 = 0, t2 = 0;
  for (int i = 0; i < n; i++) {
    if (r[i]) {
      cout << t1 << " \n"[i==n-1];
      t1 += a[i];
    } else {
      cout << t2 << " \n"[i==n-1];
      t2 += a[i];
    }
  }
}
