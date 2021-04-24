// https://codeforces.com/contest/1517/problem/C
#include <bits/stdc++.h>

using namespace std;
const int N = 505;
int xs[N][N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> xs[i][i];
  for (int ii = 0; ii < n; ii++) {
    int k = xs[ii][ii];
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {-1, 0, 1, 0};
    int y = ii, x = ii;
    for (int j = 1; j < k; j++)
      for (int i = 0; i < 4; i++) {
        int yy = y + dy[i], xx = x + dx[i];
        if (yy >= 0 && yy < n && xx >= 0 && xx < n && !xs[yy][xx]) {
          xs[yy][xx] = k;
          y = yy, x = xx;
          break;
        }
      }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      if (!xs[i][j]) {
        cout << "-1\n";
        return 0;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) cout << xs[i][j] << " \n"[j == i];
}
