// https://codeforces.com/contest/1241/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  int q;
  cin >> q;
  while (q--) {
    ll n, x, a, y, b, k;
    cin >> n;
    vi c(n);
    for (int i = 0; i < n; i++) cin >> c[i], c[i] /= 100;
    cin >> x >> a >> y >> b >> k;
    if (y > x) swap(a, b), swap(x, y);
    ll ab = (a * b) / __gcd(a, b);
    sort(c.begin(), c.end(), greater<ll>());
    int l = 0;
    for (int e = (n + 1) / 2; e >= 1; e /= 2) {
      while (l + e <= n) {
        ll d = (l + e);
        ll dab = d / ab, da = d / a - dab, db = d / b - dab;
        ll sab = 0, sa = 0, sb = 0;
        for (int m = 0; m < dab; m++) sab += c[m];
        for (int m = 0; m < da; m++) sa += c[dab + m];
        for (int m = 0; m < db; m++) sb += c[dab + da + m];
        if ((x + y) * sab + x * sa + y * sb < k) l += e;
        else break;
      }
    }
    if (l < n) cout << l + 1 << endl;
    else cout << "-1\n";
  }
}
