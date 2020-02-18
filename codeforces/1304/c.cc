// https://codeforces.com/contest/1304/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using iii = tuple<ll, ll, ll>;
using viii = vector<iii>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll q, n, m, t, l, h;
  cin >> q;
  while (q--) {
    cin >> n >> m;
    viii a(n);
    for (int i = 0; i < n; i++) {
      cin >> t >> l >> h;
      a[i] = {t, l, h};
    }
    ll t0 = 0, mn = m, mx = m;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      tie(t, l, h) = a[i];
      mn -= (t-t0);
      mx += (t-t0);
      if (l > mx || h < mn) { ok = 0; break; }
      mn = max(mn, l);
      mx = min(mx, h);
      t0 = t;
    }
    cout << (ok?"YES\n":"NO\n");
  }
}
