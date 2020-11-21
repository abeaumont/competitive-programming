// https://cses.fi/problemset/task/1639
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vvi a(n + 1, vi(m + 1, 0));
  for (int i = 1; i <= n; i++) a[i][0] = i;
  for (int i = 1; i <= m; i++) a[0][i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] = min(a[i - 1][j - 1] + (s[i - 1] != t[j - 1]),
                    min(a[i - 1][j], a[i][j - 1]) + 1);
  cout << a[n][m] << "\n";
}
