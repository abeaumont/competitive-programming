// https://atcoder.jp/contests/abc149/tasks/abc149_e
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, m;
vector<ll> a, b;

ll count(ll sum) {
  ll c = 0;
  for (int i = 0; i < n; i++) {
    c += n - (lower_bound(a.rbegin(), a.rend(), sum - a[i]) - a.rbegin());
  }
  return c;
}

ll sum(ll sum) {
  ll s = 0;
  for (int i = 0; i < n; i++) {
    ll k = n - (lower_bound(a.rbegin(), a.rend(), sum - a[i]) - a.rbegin());
    if (k > 0) s += a[i] * k + b[k - 1];
  }
  return s;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  a = vector<ll>(n), b = vector<ll>(n);
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
    if (i) b[i] += b[i - 1];
  }

  ll k = -1;
  for (ll b = 1e5; b >= 1; b /= 2)
    while (count(k + b) > m) k += b;
  ll s = sum(k) - (count(k) - m) * k;
  cout << s << '\n';
}
