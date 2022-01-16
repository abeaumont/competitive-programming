// https://codeforces.com/contest/1627/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, m, r, c;
  cin >> t;
  while (t--) {
    cin >> n >> m >> r >> c;
    r--, c--;
    ll ans = 3;
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++)
        if (s[j] == 'B') {
          if (r == i && c == j) ans = 0;
          else if (r == i || c == j)
            ans = min(ans, 1LL);
          else
            ans = min(ans, 2LL);
        }
    }
    if (ans == 3) ans = -1;
    cout << ans << '\n';
  }
}
