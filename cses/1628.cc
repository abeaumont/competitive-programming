// https://cses.fi/problemset/task/1628
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using mii = map<ll, ll>;

ll x, s;

void f(mii& b, vi &a, int i, ll k) {
  if (k > x) return;
  if (i == a.size()) b[k]++;
  else f(b, a, i + 1, k), f(b, a, i + 1, k + a[i]);
}

int main() {
  int n, p, q;
  cin >> n >> x;
  p = n / 2;
  q = n - p;
  vi a(p), b(q);
  for (int i = 0; i < p; i++) cin >> a[i];
  for (int i = 0; i < q; i++) cin >> b[i];
  mii c, d;
  f(c, a, 0, 0), f(d, b, 0, 0);
  for (auto y : c) s += y.second * d[x - y.first];
  cout << s << "\n";
}
