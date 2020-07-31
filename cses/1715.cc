// https://cses.fi/problemset/task/1715
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000;
ll M = 1000000007;
int freq[26];
ll f[N + 1], inv[N + 1], invf[N + 1];

ll modinv(ll a, ll b) {
  ll b0 = b, t, q;
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
  string s;
  cin >> s;
  int n = s.size();
  f[0] = f[1] = 1;
  for (int i = 2; i <= N; i++)
    f[i] = f[i - 1] * i % M;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= N; i++)
    inv[i] = M - (M / i) * inv[M % i] % M;
  invf[0] = 1, invf[1] = 1;
  for (int i = 2; i <= N; i++)
    invf[i] = invf[i - 1] * inv[i] % M;
  for (int x : s)
    freq[x - 'a']++;
  ll r = f[n];
  for (int i = 0; i < 26; i++)
    (r *= invf[freq[i]]) %= M;
  if (r < 0)
    r += M;
  cout << r << '\n';
}
