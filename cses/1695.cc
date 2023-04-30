// https://cses.fi/problemset/task/1695/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 500;
int n;
ll g[N][N], c, f;
vector<bool> s;

ll dfs(int i) {
  s[i] = 1;
  if (i == n - 1) {
    f++;
    return 1;
  }
  for (int j = 0; j < n; j++)
    if (!s[j] && g[i][j])
      if (dfs(j)) {
        g[i][j]--;
        g[j][i]++;
        return 1;
      }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    g[a][b] = g[b][a] = 1;
  }
  s = vector<bool>(n);
  while (dfs(0)) fill(s.begin(), s.end(), 0);
  cout << f << '\n';
  fill(s.begin(), s.end(), 0);
  s[0] = 1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    a = q.front();
    q.pop();
    for (int b = 0; b < n; b++)
      if (!s[b] && g[a][b]) s[b] = 1, q.push(b);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (s[i] && !s[j] && g[j][i]) cout << i + 1 << ' ' << j + 1 << '\n';
}
