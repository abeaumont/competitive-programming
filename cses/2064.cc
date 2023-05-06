// https://cses.fi/problemset/task/2064
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

int main() {
  cin.tie(0), ios::sync_with_stdio();
  f[0] = finv[0] = 1;
  for (ll i = 1; i <= N; i++) {
    f[i] = f[i - 1] * i % M;
    finv[i] = finv[i - 1] * modinv(i) % M;
  }
  int n;
  cin >> n;
  if (n & 1) cout << "0\n";
  else
    cout << f[n] * finv[n / 2] % M * finv[n / 2] % M * modinv(n / 2 + 1) % M
         << '\n';
}
