// https://open.kattis.com/problems/knapsack
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int c, n;
  while (cin >> c >> n) {
    vi v(n), w(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    vvi d(c + 1, vi(n + 1));
    for (int i = 1; i <= c; i++)
      for (int j = 1; j <= n; j++) {
        d[i][j] = d[i][j - 1];
        if (w[j - 1] <= i)
          d[i][j] = max(d[i][j], d[i - w[j - 1]][j - 1] + v[j - 1]);
      }
    vi ans;
    for (int i = n; i >= 1; i--)
      if (d[c][i] != d[c][i - 1]) ans.push_back(i - 1), c -= w[i - 1];
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}
