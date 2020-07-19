// https://cses.fi/problemset/task/1687
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, c = 1, k = 1, x;
  cin >> n >> q;
  while (k <= n)
    c++, k *= 2;
  vvi a(c, vi(n));
  a[0][0] = -1;
  for (int i = 1; i < n; i++)
    cin >> a[0][i], a[0][i]--;
  for (int i = 1; i < c; i++)
    for (int j = 0; j < n; j++)
      if (a[i - 1][j] == -1)
        a[i][j] = -1;
      else
        a[i][j] = a[i - 1][a[i - 1][j]];
  for (int i = 0; i < q; i++) {
    cin >> x >> k;
    x--;
    while (k > 0) {
      int d = log2(k);
      x = a[d][x];
      if (x == -1)
        break;
      k -= exp2(d);
    }
    if (x >= 0)
      x++;
    cout << x << '\n';
  }
}
