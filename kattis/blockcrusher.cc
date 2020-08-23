// https://open.kattis.com/problems/blockcrusher
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using pq = priority_queue<iii, vector<iii>, greater<iii>>;

int main() {
  while (1) {
    int h, w, r, c, k;
    cin >> h >> w;
    if (!h) break;
    vs block(h);
    for (int i = 0; i < h; i++) cin >> block[i];
    pq q;
    for (int i = 0; i < w; i++) q.push({block[0][i] - '0', 0, i});
    vvi v(h, vi(w));
    vvii p(h, vii(w));
    while (1) {
      tie(k, r, c) = q.top();
      q.pop();
      if (r + 1 == h) {
        while (1) {
          block[r][c] = ' ';
          if (!r) break;
          tie(r, c) = p[r][c];
        }
        for (auto s : block) cout << s << '\n';
        cout << '\n';
        break;
      }
      for (int dy : {-1, 0, 1})
        for (int dx : {-1, 0, 1}) {
          int y = r + dy, x = c + dx;
          if (y >= 0 && y < h && x >= 0 && x < w && !v[y][x]) {
            v[y][x] = 1;
            p[y][x] = {r, c};
            q.push({k + block[y][x] - '0', y, x});
          }
        }
    }
  }
}
