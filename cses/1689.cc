// https://cses.fi/problemset/task/1689
#include <bits/stdc++.h>

using namespace std;
const int N = 8;
int dy[N] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[N] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dp[N][N];

bool dfs(int r, int c, int i) {
  dp[r][c] = i;
  if (i == N * N) return 1;
  vector<pair<int, int>> m;
  for (int i = 0; i < N; i++) {
    int y = r + dy[i], x = c + dx[i];
    if (y >= 0 && y < N && x >= 0 && x < N && !dp[y][x]) {
      int c = 0;
      for (int j = 0; j < N; j++) {
        int yy = y + dy[j], xx = x + dx[j];
        c += (yy >= 0 && yy < N && xx >= 0 && xx < N && !dp[yy][xx]);
      }
      m.emplace_back(c, i);
    }
  }
  sort(m.begin(), m.end());
  for (auto [v, k] : m)
    if (dfs(r + dy[k], c + dx[k], i + 1)) return 1;
  dp[r][c] = 0;
  return 0;
}

int main() {
  int x, y;
  cin >> x >> y;
  dfs(y - 1, x - 1, 1);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cout << dp[i][j] << " \n"[j == N - 1];
}
