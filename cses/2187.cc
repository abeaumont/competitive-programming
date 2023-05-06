// https://cses.fi/problemset/task/2187
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
const int N = 1e6;
ll f[N + 1], finv[N + 1];

ll modpow(ll b, ll e) {
  ll p = 1;
  for (ll i = 0; (1LL << i) <= e; i++, (b *= b) %= M)
    if (e & (1LL << i)) (p *= b) %= M;
  if (p < 0) p += M;
  return p;
}

ll modinv(ll x) { return modpow(x, M - 2); }

ll binomial(ll n, ll k) {
  if (k > n) return 0;
  return f[n] * finv[k] % M * finv[n - k] % M;
}

int main() {
  cin.tie(0), ios::sync_with_stdio();
  f[0] = finv[0] = 1;
  for (ll i = 1; i <= N; i++) {
    f[i] = f[i - 1] * i % M;
    finv[i] = finv[i - 1] * modinv(i) % M;
  }
  int n, l = 0, r = 0, ok = 1;
  string s;
  cin >> n >> s;
  for (char c : s)
    if (c == '(') l++;
    else {
      if (++r > l) ok = 0;
    }
  if (!ok || (n & 1)) {
    cout << "0\n";
    return 0;
  }
  int k = n - l - r;
  int m = min(l, r);
  ll ans = (binomial(k, n / 2 - l) - binomial(k, (n / 2 - r + 1))) % M;
  if (ans < 0) ans += M;
  cout << ans << '\n';
}
