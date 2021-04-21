// https://open.kattis.com/problems/sylvester
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, x, y, w, h;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y >> w >> h;
    for (ll i = y; i < y + h; i++)
      for (ll j = x; j < x + w; j++) {
        ll s = 1, r = i, c = j;
        for (ll k = n; k > 1; k /= 2) {
          if (r >= k / 2 && c >= k / 2) s *= -1;
          if (r >= k / 2) r -= k / 2;
          if (c >= k / 2) c -= k / 2;
        }
        cout << s << " \n"[j == x + w - 1];
      }
    if (t) cout << '\n';
  }
}
