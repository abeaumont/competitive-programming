// https://open.kattis.com/problems/granica
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<tuple<ll, ll>> f;

void d(ll i, ll x) {
  if (i == f.size()) {
    if (x > 1) cout << x << ' ';
    return;
  }
  ll k, c;
  tie(k, c) = f[i];
  ll y = 1;
  for (ll j = 0; j <= c; j++) d(i + 1, x * y), y *= k;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll g = a[1] - a[0];
  for (int i = 2; i < n; i++) g = gcd(g, a[i] - a[i - 1]);
  for (ll i = 2; i * i <= g; i++) {
    ll c = 0;
    while (!(g % i)) {
      c++;
      g /= i;
    }
    if (c) f.push_back({i, c});
  }
  if (g > 1) f.push_back({g, 1});
  d(0, 1);
  cout << '\n';
}
