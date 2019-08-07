// https://cses.fi/problemset/stats/1662/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vvi a(n);
  vi b(n + 1);
  a[0].push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> b[i + 1];
    (b[i + 1] += b[i]) %= n;
    if (b[i + 1] < 0) b[i + 1] += n;
    a[b[i + 1]].push_back(i + 1);
  }
  ll s = 0;
  for (int i = 1; i <= n; i++) {
    ll x = (b[i] - n) % n;
    if (x < 0) x += n;
    s += lower_bound(a[x].begin(), a[x].end(), i) - a[x].begin();
  }
  cout << s << "\n";
}
