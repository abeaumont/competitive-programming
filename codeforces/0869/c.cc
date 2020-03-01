// https://codeforces.com/contest/869/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 998244353;
const ll N = 5000;
ll p[N+1], inv[N+1], invp[N+1];

ll binomial(ll n, ll k, ll m) {
  ll c = 1;
  while (n||k) {
    ll a = n%m, b = k%m;
    if (a<b) return 0;
    c = c*p[a]%m * invp[b]%m * invp[a-b]%m;
    n/=m, k/=m;
  }
  return c;
}

int main() {
  p[1] = inv[1] = invp[0] = 1;
  for (int i=2; i<=N; i++) p[i] = p[i-1]*i%M;
  for (int i=2; i<=N; i++) inv[i] = M-(M/i)*inv[M%i]%M;
  for (int i=1; i<=N; i++) invp[i] = invp[i-1] * inv[i]%M;
  ll a, b, c;
  cin >> a >> b >> c;
  ll ab = 0, ac = 0, bc = 0;
  for (int i = 1; i <= min(a, b); i++)
    (ab += binomial(a, i, M)*binomial(b, i, M)%M*p[i]%M) %= M;
  for (int i = 1; i <= min(a, c); i++)
    (ac += binomial(a, i, M)*binomial(c, i, M)%M*p[i]%M) %= M;
  for (int i = 1; i <= min(b, c); i++)
    (bc += binomial(b, i, M)*binomial(c, i, M)%M*p[i]%M) %= M;
  ll t = (1 + (ab+ac+bc)%M + ab*ac%M+ab*bc%M+ac*bc%M + ab*ac%M*bc%M)%M;
  cout << t << '\n';
}
