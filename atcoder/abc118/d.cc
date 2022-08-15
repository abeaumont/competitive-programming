// https://atcoder.jp/contests/abc118/tasks/abc118_d
#include <bits/stdc++.h>

using namespace std;
const int N = 1e4;
int ms[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6}, d[N][11], a[9];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, x;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i], a[i]--;
  sort(a, a + m);
  reverse(a, a + m);
  d[0][m] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (ms[a[j]] > i || !d[i - ms[a[j]]][m] ||
          d[i][m + 1] > d[i - ms[a[j]]][m + 1] + 1)
        continue;
      vector<int> x(m);
      for (int k = 0; k < m; k++)
        if (k != j) x[k] = d[i - ms[a[j]]][k];
      x[j] = d[i - ms[a[j]]][j] + 1;
      int c = 0;
      for (int k = 0; k < m; k++) {
        if (d[i][k] > x[k]) c = 1;
        else if (d[i][k] < x[k])
          c = -1;
        if (c) break;
      }
      if (d[i][m + 1] == d[i - ms[a[j]]][m + 1] + 1 && c > 0) continue;
      for (int k = 0; k < m; k++) d[i][k] = x[k];
      d[i][m] = 1;
      d[i][m + 1] = d[i - ms[a[j]]][m + 1] + 1;
    }
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < d[n][i]; j++) cout << a[i] + 1;
  cout << '\n';
}
