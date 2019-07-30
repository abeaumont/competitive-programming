// https://codeforces.com/contest/1199/problem/D

#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  int n, q;
  int t, p, x;
  cin >> n;
  vi a(n), z(n, -1);
  for (int i = 0; i < n; i++) cin >> a[i];
  vii b;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) cin >> p;
    else p = 0;
    cin >> x;
    b.push_back({p, x});
  }
  int l = -1;
  for (int i = q - 1; i >= 0; i--) {
    tie(p, x) = b[i];
    if (!p) l = max(l, x);
    else if (z[p - 1] == -1)  z[p - 1] = max(x, l);
  }
  for (int i = 0; i < n; i++)
    if (z[i] == -1) z[i] = max(l, a[i]);
  for (int i = 0; i < n; i++)
    cout << z[i] <<" \n"[i == n-1];
}
