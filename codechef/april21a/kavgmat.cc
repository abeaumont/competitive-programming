// https://www.codechef.com/APRIL21A/problems/KAVGMAT
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i + 1][j + 1];
        a[i + 1][j + 1] += a[i][j + 1] + a[i + 1][j] - a[i][j];
      }
    int ans = 0;
    for (ll l = 1; l <= n; l++)
      for (int i = 0; i <= n - l; i++) {
        int p = -1;
        for (int b = (m - l + 1); b >= 1; b /= 2) {
          while (p + b <= (m - l)) {
            int c = p + b;
            if (a[i + l][c + l] + a[i][c] - a[i + l][c] - a[i][c + l] >=
                k * l * l)
              break;
            p += b;
          }
        }
        ans += m - l - p;
      }
    cout << ans << '\n';
  }
}
