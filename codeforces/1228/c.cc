// https://codeforces.com/contest/1228/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll M = 1000000007;

ll pow(ll a, ll b, ll m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) (r *= e) %= m;
    (e *= e) %= m;
    b >>= 1;
  }
  return r;
}
int main() {
  ll x, n;
  cin >> x >> n;
  vi p;
  if (!(x % 2)) p.push_back(2);
  while (x > 1 && !(x % 2)) x /= 2;
  for (ll i = 3; i * i <= x; i += 2) {
    if (x > 1 && !(x % i)) {
      while (!(x % i)) x /= i;
      p.push_back(i);
    }
  }
  if (x > 1) p.push_back(x);
  ll r = 1;
  for (ll a : p) {
    ll b = a;
    ll c = 0;
    while (b <= n) {
      c += n / b;
      if (LLONG_MAX / b < a) break;
      b *= a;
    }
    (r *= pow(a, c, M)) %= M;
  }
  cout << r << endl;
}
