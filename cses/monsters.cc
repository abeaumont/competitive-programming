// https://cses.fi/problemset/task/1194/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<string> vs;
typedef deque<iii> qiii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;
vs map;

bool valid(int y, int x, int distance) {
  qiii q;
  q.push_back({y, x, 0});
  vvb visited(n, vb(m));
  visited[y][x] = true;
  while (true) {
    if (q.empty()) return true;
    int d;
    tie(y, x, d) = q.front(); q.pop_front();
    if (map[y][x] == 'M') return false;
    if (d >= distance) continue;
    if (y > 0 && !visited[y - 1][x] && (map[y - 1][x] == '.' || map[y - 1][x] == 'M')) {
      visited[y - 1][x] = true;
      q.push_back({y - 1, x, d + 1});
    }
    if (y < n - 1 && !visited[y + 1][x] && (map[y + 1][x] == '.' || map[y + 1][x] == 'M')) {
      visited[y + 1][x] = true;
      q.push_back({y + 1, x, d + 1});
    }
    if (x > 0 && !visited[y][x - 1] && (map[y][x - 1] == '.' || map[y][x - 1] == 'M')) {
      visited[y][x - 1] = true;
      q.push_back({y, x - 1, d + 1});
    }
    if (x < m - 1 && !visited[y][x + 1] && (map[y][x + 1] == '.' || map[y][x + 1] == 'M')) {
      visited[y][x + 1] = true;
      q.push_back({y, x + 1, d + 1});
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  map = vs(n);
  for (int i = 0; i < n; i++) cin >> map[i];
  int y = -1, x = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 'A') {
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  qiii q;
  q.push_back({y, x, 0});
  vvb visited(n, vb(m));
  visited[y][x] = true;
  vvii p(n, vii(m));
  string path;
  int ay = y, ax = x;
  bool found = false;
  while (true) {
    if (q.empty()) break;
    int d;
    tie(y, x, d) = q.front(); q.pop_front();
    if (y == 0 || y == n - 1 || x == 0 || x == m - 1) {
      if (valid(y, x, d)) {
        found = true;
        while (y != ay || x != ax) {
          int py, px;
          tie(py, px) = p[y][x];
          if (y > py) path.push_back('D');
          else if (y < py) path.push_back('U');
          else if (x > px) path.push_back('R');
          else if (x < px) path.push_back('L');
          else assert(false);
          y = py; x = px;
        }
        reverse(path.begin(), path.end());
        break;
      }
    }
    if (y > 0 && !visited[y - 1][x] && map[y - 1][x] == '.') {
      p[y - 1][x] = {y, x};
      visited[y - 1][x] = true;
      q.push_back({y - 1, x, d + 1});
    }
    if (y < n - 1 && !visited[y + 1][x] && map[y + 1][x] == '.') {
      p[y + 1][x] = {y, x};
      visited[y + 1][x] = true;
      q.push_back({y + 1, x, d + 1});
    }
    if (x > 0 && !visited[y][x - 1] && map[y][x - 1] == '.') {
      p[y][x - 1] = {y, x};
      visited[y][x - 1] = true;
      q.push_back({y, x - 1, d + 1});
    }
    if (x < m - 1 && !visited[y][x + 1] && map[y][x + 1] == '.') {
      p[y][x + 1] = {y, x};
      visited[y][x + 1] = true;
      q.push_back({y, x + 1, d + 1});
    }
  }
  if (found) cout << "YES\n" << path.size() << endl << path << endl;
  else cout << "NO\n";
}
