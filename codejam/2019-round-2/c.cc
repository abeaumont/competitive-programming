// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146184
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = tuple<ll, ll>;
using vii = vector<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t, n, x, y, x1, y1, x2, y2;
  ii m, M;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n;
    vii a(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      a[i] = {x, y};
    }
    bool ok = true, ms = false, Ms = false;
    for (int i = 1; i < n; i++) {
      tie(x1, y1) = a[i - 1];
      tie(x2, y2) = a[i];
      if ((x1 == x2 && y1 >= y2) || (y1 == y2 && x1 >= x2)) {
        ok = false;
        break;
      }
      if ((x1 == x2 || y1 == y2) || (x2 > x1 && y2 > y1)) continue;
      if (x1 > x2 && y1 > y2) {
        ok = false;
        break;
      }
      if (x1 > x2) {
        x = x1 - x2, y = y2 - y1;
        ll g = __gcd(x, y);
        x /= g, y /= g;
        if (!ms) m = { x, y };
        else {
          tie(x1, y1) = m;
          if (x1 * y < x * y1) m = { x, y };
        }
        ms = true;
      } else {
        x = x2 - x1, y = y1 - y2;
        ll g = __gcd(x, y);
        x /= g, y /= g;
        if (!Ms) M = { x, y };
        else {
          tie(x1, y1) = M;
          if (x1 * y > x * y1) M = {x, y};
        }
        Ms = true;
      }
    }
    if (!ms) m = { 0, 1 };
    if (!Ms) M = { 1, 0 };
    tie(x1, y1) = m, tie(x2, y2) = M;
    if (x1 * y2 >= x2 * y1) ok = false;
    cout << "Case #" << T << ": ";
    if (ok) {
      ll nl = 0, dl = 1, nr = 1, dr = 0;
      while (true) {
        x = nl + nr, y = dl + dr;
        if (x * y2 >= x2 * y) nr = x, dr = y;
        else if (x * y1 <= x1 * y) nl = x, dl = y;
        else break;
      }
      cout << y << " " << x << "\n";
    } else cout << "IMPOSSIBLE\n";
  }
}
