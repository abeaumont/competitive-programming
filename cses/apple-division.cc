// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

ll n, m, t;
vi a;

void f(int i, ll s) {
  if (i == n) {
    ll x = s;
    ll y = t - s;
    if (y > x) swap(x, y);
    m = min(x - y, m);
    return;
  }
  f(i + 1, s);
  f(i + 1, s + a[i]);
}

int main() {
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      t += a[i];
    }
    m = t;
    f(0, 0);
    cout << m << endl;
}
