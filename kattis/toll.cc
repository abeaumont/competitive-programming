// https://open.kattis.com/problems/toll
#include <bits/stdc++.h>

using namespace std;

int st[131072][25];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int k, n, m, o, a, b, t, s = 1, p;
  cin >> k >> n >> m >> o;
  p = (n - 1) / k;
  while (s < p) s *= 2;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> t;
    int j = a / k, c = a % k, d = b % k;
    st[s + j][c * k + d] = t;
  }
  for (int i = s - 1; i > 0; i--)
    for (int ii = 0; ii < k; ii++)
      for (int jj = 0; jj < k; jj++) {
        int mn = 2e9;
        for (int kk = 0; kk < k; kk++) {
          if (st[i * 2][ii * k + kk] && st[i * 2 + 1][kk * k + jj])
            mn = min(mn, st[i * 2][ii * k + kk] + st[i * 2 + 1][kk * k + jj]);
        }
        if (mn < 2e9) st[i][ii * k + jj] = mn;
      }
  while (o--) {
    cin >> a >> b;
    int l = a % k, r = b % k;
    a /= k, b /= k;
    a += s, b += s - 1;
    if (b < a) {
      cout << "-1\n";
      continue;
    }
    vector<int> as, bs;
    while (a < b) {
      if (a & 1) as.push_back(a++);
      if (!(b & 1)) bs.push_back(b--);
      a /= 2, b /= 2;
    }
    if (a == b) as.push_back(a);
    for (auto it = bs.rbegin(); it != bs.rend(); it++) as.push_back(*it);
    if (as.size() == 1) {
      int ans = st[as[0]][l * k + r];
      if (!ans) ans = -1;
      cout << ans << '\n';
      continue;
    }
    vector<int> sum(k);
    for (int i = 0; i < k; i++) {
      int v = st[as[0]][l * k + i];
      if (v) sum[i] = v;
      else
        sum[i] = -1;
    }
    for (int i = 1; i < as.size(); i++) {
      vector<int> tmp(k, -1);
      for (int jj = 0; jj < k; jj++) {
        int mn = 2e9;
        for (int kk = 0; kk < k; kk++)
          if (sum[kk] >= 0 && st[as[i]][kk * k + jj])
            mn = min(mn, sum[kk] + st[as[i]][kk * k + jj]);
        if (mn < 2e9) tmp[jj] = mn;
      }
      swap(sum, tmp);
    }
    cout << sum[r] << '\n';
  }
}
