// https://codeforces.com/contest/1406/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q;
  cin >> n;
  vi a(n);
  ll p = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 1; i--) {
    a[i] -= a[i - 1];
    if (a[i] > 0) p += a[i];
  }
  ll ans = a[0] + p;
  if (ans >= 0) ans++;
  cout << ans / 2 << '\n';
  cin >> q;
  while (q--) {
    int l, r;
    ll x;
    cin >> l >> r >> x;
    l--;
    if (l)
      if (a[l] > 0 && x > 0) p += x;
      else if (a[l] > 0 && x <= 0) {
        if (a[l] > -x) p += x;
        else
          p -= a[l];
      } else if (a[l] <= 0 && x > 0)
        if (-a[l] <= x) p += x + a[l];
    a[l] += x;
    if (r < n) {
      x = -x;
      if (a[r] > 0 && x > 0) p += x;
      else if (a[r] > 0 && x <= 0) {
        if (a[r] > -x) p += x;
        else
          p -= a[r];
      } else if (a[r] <= 0 && x > 0)
        if (-a[r] < x) p += x + a[r];
      a[r] += x;
    }
    ans = a[0] + p;
    if (ans >= 0) ans++;
    cout << ans / 2 << '\n';
  }
}
