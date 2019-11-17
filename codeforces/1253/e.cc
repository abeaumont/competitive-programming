// https://codeforces.com/contest/1253/problem/E
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  int n, m, x, s, l, r;
  cin >> n >> m;
  vii a(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> s;
    a[i] = { x - s, x + s };
  }
  vi dp(m + 1);
  for (int i = 0; i <= m; i++) dp[i] = i;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      tie(l, r) = a[j];
      if (l <= i && i <= r) dp[i] = dp[i - 1];
      else if (r < i) {
        int c = i - r;
        dp[i] = min(dp[i], dp[max(0, l - c - 1)] + c);
      }
    }
  }
  cout << dp[m] << '\n';
}
