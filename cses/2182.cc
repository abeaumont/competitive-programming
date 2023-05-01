// https://cses.fi/problemset/task/2182
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

ll modpow(ll b, ll e, ll m) {
  ll p = 1;
  for (int i = 0, x = b; (1L << i) <= e; i++, (b *= b) %= m)
    if (e & (1L << i)) (p *= b) %= m;
  return p;
}

ll modinv(ll x, ll m) { return modpow(x, m - 2, m); }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, a = 1, b = 1, c = 1, p = 1, d = 1;
  cin >> n;
  vector<ll> x(n), k(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> k[i];
    if (p && k[i] % 2) p = 0, (d *= (k[i] + 1) / 2) %= (M - 1);
    else
      (d *= (k[i] + 1)) %= (M - 1);
  }
  for (int i = 0; i < n; i++) {
    (a *= (k[i] + 1)) %= M;
    (b *= (modpow(x[i], (k[i] + 1), M) - 1) * modinv(x[i] - 1, M) % M) %= M;
    ll e = (p ? k[i] / 2 : k[i]) * d % (M - 1);
    (c *= modpow(x[i], e, M)) %= M;
  }
  if (b < 0) b += M;
  if (c < 0) c += M;
  cout << a << ' ' << b << ' ' << c << '\n';
}
