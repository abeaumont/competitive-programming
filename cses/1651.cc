// https://cses.fi/problemset/task/1651
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;

int n;
vi t;

void add(int k, ll x) {
  while (k <= n) t[k] += x, k += k & -k;
}

void add(int a, int b, ll x) {
  add(a, x), add(b + 1, -x);
}

ll sum(int k) {
  ll s = 0;
  while (k) s += t[k], k -= k & -k;
  return s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, p, x, y = 0, z;
  cin >> n >> q;
  t = vi(n + 1);
  for (int i = 1; i <= n; i++) cin >> x, add(i, x - y), y = x;
  while (q--) {
    cin >> p;
    if (p == 1) cin >> x >> y >> z, add(x, y, z);
    else cin >> x, cout << sum(x) << "\n";
  }
}
