// https://cses.fi/problemset/task/1716
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000;
ll M = 1000000007;
int freq[26];
ll f[2*N], inv[2*N], invf[2*N];

ll modinv(ll a, ll b) {
  ll t, q;
  ll x0 = 0, x1 = 1;
  if (b == 1)
    return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  return x1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  f[0] = f[1] = 1;
  for (int i = 2; i < n+m; i++)
    f[i] = f[i - 1] * i % M;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= max(n-1, m); i++)
    inv[i] = M - (M / i) * inv[M % i] % M;
  invf[0] = 1, invf[1] = 1;
  for (int i = 2; i <= max(n-1, m); i++)
    invf[i] = invf[i - 1] * inv[i] % M;
  ll r = f[n+m-1] * invf[m] % M * invf[n-1] % M;
  if (r < 0)
    r += M;
  cout << r << '\n';
}
