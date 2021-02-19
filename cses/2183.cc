// https://cses.fi/problemset/task/2183
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll mn = 1, p = 0;
  for (ll x : a) {
    if (p + mn < x) {
      cout << p + mn << '\n';
      return 0;
    }
    mn += p;
    p = x;
  }
  cout << p + mn << '\n';
}
