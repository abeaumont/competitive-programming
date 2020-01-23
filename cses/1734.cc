// https://cses.fi/problemset/task/1734/
#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int, int, int>;
using mii = map<int, int>;
using vi = vector<int>;
using viii = vector<iii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, a, b;
  cin >> n >> q;
  vi x(n);
  mii m;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    if (m.count(y)) x[i] = m[y];
    else x[i] = m.size(), m[y] = x[i];
  }
  viii y(q);
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    y[i] = {a-1, b, i};
  }
  int k = sqrt(n);
  sort(y.begin(), y.end(), [&](iii x, iii y) -> bool {
    int a1, b1, i1, a2, b2, i2;
    tie(a1, b1, i1) = x;
    tie(a2, b2, i2) = y;
    int a1q = a1/k, a2q = a2/k;
    if (a1q < a2q) return true;
    if (a1q > a2q) return false;
    return b1 < b2;
  });
  vi res(q);
  vi count(m.size());
  int l = 0, r = 0, ans = 0;
  for (iii z : y) {
    int i;
    tie(a, b, i) = z;
    while (r < b) if (++count[x[r++]] == 1) ans++;
    while (r > b) if (--count[x[--r]] == 0) ans--;
    while (l < a) if (--count[x[l++]] == 0) ans--;
    while (l > a) if (++count[x[--l]] == 1) ans++;
    res[i] = ans;
  }
  for (int z : res) cout << z << '\n';
}
