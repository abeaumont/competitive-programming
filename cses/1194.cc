// https://cses.fi/problemset/task/1194/
#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ay, ax;
  vector<pair<int, int>> ms;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'A') ay = i, ax = j;
      else if (a[i][j] == 'M')
        ms.emplace_back(i, j);
  queue<tuple<int, int, bool>> q;
  vector<vector<bool>> b(n, vector<bool>(m));
  vector<vector<int>> d(n, vector<int>(m, INF));
  for (auto [y, x] : ms) {
    q.emplace(y, x, 0);
    b[y][x] = 1;
  }
  q.emplace(ay, ax, 1);
  b[ay][ax] = 1;
  d[ay][ax] = 0;
  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, -1, 0, 1};
  string ds = "DRUL";
  int r, c, p;
  while (!q.empty()) {
    tie(r, c, p) = q.front();
    if (p && (r == 0 || r == n - 1 || c == 0 || c == m - 1)) break;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int y = r + dy[i];
      int x = c + dx[i];
      if (y >= 0 && y < n && x >= 0 && x < m && a[y][x] != '#' && !b[y][x]) {
        if (p) d[y][x] = d[r][c] + 1;
        b[y][x] = 1;
        q.emplace(y, x, p);
      }
    }
  }
  if (q.empty()) cout << "NO\n";
  else {
    string ans;
    while (d[r][c]) {
      for (int i = 0; i < 4; i++) {
        int y = r + dy[i];
        int x = c + dx[i];
        if (y >= 0 && y < n && x >= 0 && x < m && d[y][x] < d[r][c]) {
          ans.push_back(ds[i]);
          r = y, c = x;
          break;
        }
      }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << '\n' << ans << '\n';
  }
}
