// https://atcoder.jp/contests/abc154/tasks/abc154_f
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6;
const ll M = 1e9 + 7;
ll f[2 * (N + 2) + 1], inv[2 * (N + 2) + 1], finv[2 * (N + 2) + 1];

ll binomial(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return f[n] * finv[k] % M * finv[n - k] % M;
}

ll g(int n, int m) { return binomial(n + m + 2, m + 1); }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  f[0] = f[1] = 1;
  inv[0] = inv[1] = 1;
  finv[0] = finv[1] = 1;
  for (ll i = 2; i <= 2 * (N + 2); i++) {
    f[i] = f[i - 1] * i % M;
    inv[i] = M - (M / i) * inv[M % i] % M;
    finv[i] = finv[i - 1] * inv[i] % M;
  }
  cin.tie(0), ios::sync_with_stdio(0);
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll ans = (g(r2, c2) - g(r1 - 1, c2) - g(r2, c1 - 1) + g(r1 - 1, c1 - 1)) % M;
  if (ans < 0) ans += M;
  cout << ans << '\n';
}
