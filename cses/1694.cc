// https://cses.fi/problemset/task/1694/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 500;
int n;
ll g[N][N], c, f;
vector<bool> s;

ll dfs(int i, ll cap) {
  s[i] = 1;
  if (i == n - 1) {
    f += cap;
    return cap;
  }
  for (int j = 0; j < n; j++)
    if (!s[j] && g[i][j] >= c)
      if (ll cc = dfs(j, min(cap, g[i][j]))) {
        g[i][j] -= cc;
        g[j][i] += cc;
        return cc;
      }
  return 0;
}

int main() {
  int m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    g[a - 1][b - 1] += c;
  }
  s = vector<bool>(n);
  for (c = 1 << 29; c >= 1; c /= 2) {
    fill(s.begin(), s.end(), 0);
    while (dfs(0, 1e9)) fill(s.begin(), s.end(), 0);
  }
  cout << f << '\n';
}
