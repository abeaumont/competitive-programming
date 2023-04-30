// https://cses.fi/problemset/task/1190/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = (1 << 19);
tuple<ll, ll, ll, ll> t[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, q, k = 1, p, x, l1, m1, r1, l2, m2, r2, mx1, mx2;
  cin >> n >> q;
  while (k < n) k *= 2;
  for (int i = 0; i < n; i++)
    cin >> x, t[k + i] = {max(0LL, x), x, max(0LL, x), max(0LL, x)};
  for (int i = k - 1; i; i--) {
    tie(l1, m1, r1, mx1) = t[2 * i];
    tie(l2, m2, r2, mx2) = t[2 * i + 1];
    ll l = max(l1, m1 + l2), m = m1 + m2, r = max(m2 + r1, r2),
       mx = max(r1 + l2, max(mx1, mx2));
    mx = max(max(l, m), max(r, mx));
    t[i] = {l, m, r, mx};
  }
  while (q--) {
    cin >> p >> x;
    int i = k + p - 1;
    t[i] = {max(0LL, x), x, max(0LL, x), max(0LL, x)};
    for (i /= 2; i; i /= 2) {
      tie(l1, m1, r1, mx1) = t[2 * i];
      tie(l2, m2, r2, mx2) = t[2 * i + 1];
      ll l = max(l1, m1 + l2), m = m1 + m2, r = max(m2 + r1, r2),
         mx = max(r1 + l2, max(mx1, mx2));
      mx = max(max(l, m), max(r, mx));
      t[i] = {l, m, r, mx};
    }
    cout << get<3>(t[1]) << '\n';
  }
}
