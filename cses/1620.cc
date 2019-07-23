// https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll k = 1;
  while (true) {
    ll c = 0;
    for (int x : a) c += k / x;
    if (c >= t) break;
    k *= 2;
  }

  ll l = 0;
  for (ll b = k / 2; b >= 1; b /= 2)
    while (l + b <= k) {
      ll c = 0;
      for (int x : a) c += (l + b) / x;
      if (c >= t) break;
      l += b;
    }
  cout << l + 1 << endl;
}
