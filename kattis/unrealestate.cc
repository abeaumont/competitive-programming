// https://open.kattis.com/problems/unrealestate
#include <bits/stdc++.h>

using namespace std;

struct r {
  double x0, y0, x1, y1;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<r> rs(n);
  set<tuple<double, int, bool>> s;
  for (int i = 0; i < n; i++) {
    cin >> rs[i].x0 >> rs[i].y0 >> rs[i].x1 >> rs[i].y1;
    s.insert({rs[i].x0, i, 0});
    s.insert({rs[i].x1, i, 1});
  }
  set<tuple<double, int, bool>> in;
  double ans = 0;
  double px;
  for (auto [x, i, b] : s) {
    int c = 0;
    double py;
    for (auto [y, j, v] : in) {
      if (v) {
        c--;
        if (!c) ans += (y - py) * (x - px);
      } else {
        if (!c) py = y;
        c++;
      }
    }
    if (b) {
      in.erase({rs[i].y0, i, 0});
      in.erase({rs[i].y1, i, 1});
    } else {
      in.insert({rs[i].y0, i, 0});
      in.insert({rs[i].y1, i, 1});
    }
    px = x;
  }
  cout << fixed << setprecision(2) << ans << '\n';
}
