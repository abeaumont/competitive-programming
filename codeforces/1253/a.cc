// https://codeforces.com/contest/1253/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int d = 0, c = 0;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      cin >> x;
      int d2 = x - a[i];
      if (d2 < 0) ok = 0;
      if (d == d2) continue;
      if (d) {
        if (d2) ok = 0;
        d = 0;
      } else {
        if (c) ok = 0;
        d = d2;
        c++;
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";

  }
}
