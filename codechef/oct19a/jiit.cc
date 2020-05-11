// https://www.codechef.com/OCT19A/problems/JIIT
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353, N = 2000;
ll binom[N+1][N+1];
ll pow2[N+1];
ll invpow2[N+1];
ll powq[2 * (N + 1)];
int aa[2][N+1][N+1];

ll modinv(ll a, ll b) {
	ll t, q, x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b; b = a % b; a = t;
		t = x0; x0 = x1 - q * x0; x1 = t;
	}
  if (x1 < b) x1 += b;
	return x1;
}

int pow(ll a, ll b, int m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) (r *= e) %= m;
    (e *= e) %= m;
    b >>= 1;
  }
  if (r < 0) r += m;
  return r;
}

ll b(int k, int n, ll q, int i) {
  ll r = 0;
  for (int s = -n; s <= n; s += 2)
    (r += powq[s + N] * ll(aa[i][k][(n - s) / 2])) %= M;
  (r *= invpow2[n]) %= M;
  return r;
}

ll f(ll n, ll m, ll q, ll z) {
  ll r = 0;
  for (ll k1 = 0; k1 <= n; k1++) {
    ll x = z - k1 * m;
    ll y = n - 2 * k1;
    if (!y && m * k1 == z) {
      for (ll k2 = 0; k2 <= m; k2++)
        (r += b(k1, n, q, 0) * b(k2, m, q, n != m) % M * (binom[n][k1] * binom[m][k2] % M)) %= M;
      continue;
    }
    if (!y || x % y) continue;
    ll k2 = x / y;
    if (k2 < 0 || k2 > m) continue;
    (r += b(k1, n, q, 0) * b(k2, m, q, n != m) % M * (binom[n][k1] * binom[m][k2] % M)) %= M;
  }
  if (r < 0) r += M;
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pow2[0] = 1, invpow2[0] = 1;
  for (int i = 1; i <= N; i++) {
    pow2[i] = pow2[i - 1] * 2;
    if (pow2[i] >= M) pow2[i] -= M;
  }
  for (int i = 1; i <= N; i++) invpow2[i] = modinv(pow2[i], M);
  for (int i = 0; i <= N; i++) {
    binom[i][0] = binom[i][i] = 1;
    for (int j = 1; j < i; j++) {
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
      if (binom[i][j] >= M) binom[i][j] -= M;
    }
  }  
  ll t, n, m, q, z;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    cin >> n >> m >> q >> z;
    if (n % 2 == m % 2) {
      int k = max(m, n);
      for (int s = -k; s <= k; s += 2) powq[N + s] = pow(s, q, M);
    } else {
      for (int s = -n; s <= n; s += 2) powq[N + s] = pow(s, q, M);
      for (int s = -m; s <= m; s += 2) powq[N + s] = pow(s, q, M);
    }

    ll mink1 = n + 1, mink2 = m + 1;
    for (ll k1 = 0; k1 <= n; k1++) {
      ll x = z - k1 * m;
      ll y = n - 2 * k1;
      if (!y && m * k1 == z) {
        if (mink1 > k1) mink1 = k1;
        mink2 = 0;
        continue;
      }
      if (!y || x % y) continue;
      ll k2 = x / y;
      if (k2 < 0 || k2 > m) continue;
      if (mink1 > k1) mink1 = k1;
      if (mink2 > k2) mink2 = k2;
    }
    if (mink1 > n || mink2 > m) {
      cout << "0\n";
      continue;
    }
    if (n == m && mink1 > mink2) mink1 = mink2;
    for (int k = mink1; k <= n; k++) aa[0][k][0] = 1;
    for (int u = 1; u <= n; u++) {
      if (binom[n][u]) aa[0][n][u] = u & 1 ? M - binom[n][u] : binom[n][u];
      else aa[0][n][u] = 0;
    }
    for (int u = 1; u <= n; u++)
      for (int k = n - 1; k >= mink1; k--) {
        ll x = aa[0][k+1][u-1] + aa[0][k+1][u];
        if (x >= M) x -= M;
        x += aa[0][k][u-1];
        if (x >= M) x -= M;
        aa[0][k][u] = x;
      }
    if (n != m) {
      for (int k = mink2; k <= m; k++) aa[1][k][0] = 1;
      for (int u = 1; u <= m; u++) {
        if (binom[m][u]) aa[1][m][u] = u & 1 ? M - binom[m][u] : binom[m][u];
        else aa[1][m][u] = 0;
      }
      for (int u = 1; u <= m; u++)
        for (int k = m - 1; k >= mink2; k--) {
          ll x = aa[1][k+1][u-1] + aa[1][k+1][u];
          if (x >= M) x -= M;
          x += aa[1][k][u-1];
          if (x >= M) x -= M;
          aa[1][k][u] = x;
        }
    }
    cout << f(n, m, q, z) << "\n";
  }
}
