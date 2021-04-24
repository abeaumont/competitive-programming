// https://codeforces.com/contest/1517/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using iii = tuple<int, int, int>;
using viii = vector<iii>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vvi b(n, vi(m)), c(n, vi(m, -1)), d(m, vi(n, -1));
    viii e;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        e.push_back({b[i][j], i, j});
      }
    sort(e.begin(), e.end());
    for (int i = 0; i < m; i++) {
      int u, v, w;
      tie(w, u, v) = e[i];
      c[u][v] = i;
      d[i][u] = v;
    }
    int k = m;
    vvi f(n);
    for (int i = m; i < n * m; i++) {
      int u, v, w;
      tie(w, u, v) = e[k++];
      f[u].push_back(v);
    }
    vi ks(n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (d[i][j] < 0) {
          int v = f[j][ks[j]++];
          c[j][v] = i;
          d[i][j] = v;
        }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int k = d[j][i];
        cout << b[i][k] << " \n"[j == m - 1];
      }
  }
}
