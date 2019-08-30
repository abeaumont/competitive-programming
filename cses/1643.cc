// https://cses.fi/problemset/task/1643/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, s = 0, m = -2000000000;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    s = max(s + a[i], a[i]);
    m = max(m, s);
  }
  cout << m << "\n";
}
