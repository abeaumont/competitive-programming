// https://www.codechef.com/FEB20A/problems/LONGCOOK
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int n = 400 * 12;
int s[n];

bool isleap(int y) {
  if (y % 400 == 0) return 1;
  if (y % 100 == 0) return 0;
  return y % 4 == 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll d = 0;
  for (int i = 0; i < n; i++) {
    int y = (i / 12) + 1, m = (i % 12) + 1;
    if (m == 2) {
      if (isleap(y)) {
        if (d % 7 == 5) s[i]++;
        d += 29;
      } else {
        if (d % 7 >= 5) s[i]++;
        d += 28;
      }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) d += 30;
    else d += 31;
    if (i) s[i] += s[i-1];
  }
  int t;
  cin >> t;
  while (t--) {
    ll m1, y1, m2, y2;
    cin >> m1 >> y1 >> m2 >> y2;
    m1--, y1--, m2--, y2--;
    ll i1 = y1 * 12 + m1;
    ll i2 = y2 * 12 + m2;
    ll l = i1 ? ((i1 - 1) / n + 1) : 0;
    ll r = (i2 + 1) / n - 1;
    if (l > r) {
      ll c = (i2 - i1) / n * s[n-1];
      i1 %= n;
      i2 %= n;
      if (i1 > i2) c += s[n-1];
      c += s[i2];
      if (i1) c -= s[i1-1];
      cout << c << '\n';
      continue;
    }
    i1 %= n;
    i2 %= n;
    ll c = s[n-1] * (r - l + 1);
    if (i1) c += s[n-1] - s[i1-1];
    if (i2 < n-1) c += s[i2];
    cout << c << '\n';
  }
}
