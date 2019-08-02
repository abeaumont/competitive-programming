// https://cses.fi/problemset/task/1746
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int M = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vvi s(n, vi(m + 1));
  for (int j = 1; j <= m; j++)
    if (a[0] && j == a[0] || !a[0])
      s[0][j] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] && j == a[i] || !a[i])
        for (int k = max(0, j - 1); k <= min(m, j + 1); k++)
          (s[i][j] += s[i - 1][k]) %= M;
  int c = 0;
  for (int i = 1; i <= m; i++)
    (c += s[n - 1][i]) %= M;
  cout << c << "\n";
}    
