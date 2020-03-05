// https://codeforces.com/contest/1316/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;
using qii = queue<ii>;

int n;
vvi xs, ys, zs;
vvi s;

bool dfs(int y, int x) {
  s[y][x] = 1;
  int dys[] = {-1,0,1,0};
  int dxs[] = {0,-1,0,1};
  for (int i = 0; i < 4; i++) {
    int dy = y+dys[i];
    int dx = x+dxs[i];
    if (dy < 0 || dy >= n) continue;
    if (dx < 0 || dx >= n) continue;
    if (xs[dy][dx] != -2 || ys[dy][dx] != -2) continue;
    if (s[dy][dx]) {
      if (i==0) zs[y][x] = 'U';
      else if (i==1) zs[y][x] = 'L';
      else if (i==2) zs[y][x] = 'D';
      else zs[y][x] = 'R';
      return true;
    }
    if (zs[dy][dx]) continue;
    if (dfs(dy, dx)) {
      if (i==0) zs[y][x] = 'U';
      else if (i==1) zs[y][x] = 'L';
      else if (i==2) zs[y][x] = 'D';
      else zs[y][x] = 'R';
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int x, y;
  cin >> n;
  xs = vvi(n, vi(n)), ys = vvi(n, vi(n)), zs = vvi(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> y >> x, xs[i][j]=x-1, ys[i][j]=y-1;
  qii q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (ys[i][j] == i && xs[i][j] == j)
        zs[i][j] = 'X', q.push({i, j});
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    int dys[] = {-1,0,1,0};
    int dxs[] = {0,-1,0,1};
    for (int i = 0; i < 4; i++) {
      int dy = y+dys[i];
      int dx = x+dxs[i];
      if (dy < 0 || dy >= n) continue;
      if (dx < 0 || dx >= n) continue;
      if (zs[dy][dx]) continue;
      if (xs[dy][dx] != xs[y][x]) continue;
      if (ys[dy][dx] != ys[y][x]) continue;
      if (i==0) zs[dy][dx] = 'D';
      else if (i==1) zs[dy][dx] = 'R';
      else if (i==2) zs[dy][dx] = 'U';
      else zs[dy][dx] = 'L';
      q.push({dy, dx});
    }
  }
  s = vvi(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (zs[i][j]) continue;
      if (xs[i][j] != -2 || ys[i][j] != -2) {
        cout << "INVALID\n";
        return 0;
      }
      if (!dfs(i, j)) {
        cout << "INVALID\n";
        return 0;
      }
    }
  cout << "VALID\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << char(zs[i][j]);
    cout << endl;
  }
}
