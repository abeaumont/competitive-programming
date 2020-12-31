// https://open.kattis.com/problems/oceancurrents
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using viii = vector<iii>;
using vvi = vector<vi>;
using pq = priority_queue<iii, viii, greater<iii>>;

const int INF = 1e9;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int r, c, q, rs, cs, rd, cd, w, py, px;
  cin >> r >> c;
  vvi m(r, vi(c));
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) m[i][j] = s[j] - '0';
  }
  cin >> q;
  while (q--) {
    cin >> rs >> cs >> rd >> cd;
    rs--, cs--, rd--, cd--;
    vvi d(r, vi(c, INF));
    pq q;
    d[rs][cs] = 0;
    q.push({0, rs, cs});
    while (1) {
      tie(w, py, px) = q.top();
      if (py == rd && px == cd) break;
      q.pop();
      for (int i = 0; i < 8; i++) {
        int dy, dx;
        ii ds[] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                   {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
        tie(dy, dx) = ds[i];
        int y = py + dy, x = px + dx;
        if (y < 0 || y >= r || x < 0 || x >= c) continue;
        int v = m[py][px] != i;
        if (w + v < d[y][x]) d[y][x] = w + v, q.push({w + v, y, x});
      }
    }
    cout << w << '\n';
  }
}
