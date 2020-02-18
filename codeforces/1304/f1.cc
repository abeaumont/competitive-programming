// https://codeforces.com/contest/1304/problem/F1
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vii = vector<ii>;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vvi a(n+1, vi(m+1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j], a[i][j] += a[i][j-1];
  vvi dp(n+1, vi(m+1));
  vii b(1, {0, m+2}), c;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      ll r = j+k-1;
      if (r > m) r = m;
      ll bs = a[i][r] - a[i][j-1];
      if (i < n) bs += a[i+1][r] - a[i+1][j-1];
      for (ii z : b) {
        ll w, l;
        tie(w, l) = z;
        ll s = bs;
        s += w;
        if (s <= dp[i][j]) break;
        ll li = max(l, j);
        ll ri = min(l+k-1, r);
        if (li <= ri) s -= a[i][ri] - a[i][li-1];
        if (s > dp[i][j]) dp[i][j] = s;
        if (li > ri) break;
      }
      c.push_back({dp[i][j], j});
    }
    sort(c.begin(), c.end(), greater<ii>());
    swap(b, c);
    c.clear();
  }
  cout << get<0>(b[0]) << '\n';
}
