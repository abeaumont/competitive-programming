// https://cses.fi/problemset/task/1750
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int M = 1000000000;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, c = 1, k = 1, x;
  cin >> n >> q;
  while (k <= M) c++, k *= 2;
  vvi a(c, vi(n));
  for (int i = 0; i < n; i++) cin >> a[0][i], a[0][i]--;
  for (int i = 1; i < c; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = a[i-1][a[i-1][j]];
  for (int i = 0; i < q; i++) {
    cin >> x >> k;
    x--;
    while (k > 0) {
      int d = log2(k);
      x = a[d][x];
      k -= exp2(d);
    }
    cout << x+1 << '\n';
  }
}
