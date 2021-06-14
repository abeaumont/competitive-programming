// https://open.kattis.com/problems/exactchange2
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5, INF = 1e4;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, p, n, x;
  cin >> t;
  while (t--) {
    cin >> p >> n;
    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      for (int j = N; j >= x; j--) dp[j] = min(dp[j], dp[j - x] + 1);
    }
    int i = p;
    while (dp[i] == INF) i++;
    cout << i << ' ' << dp[i] << '\n';
  }
}
