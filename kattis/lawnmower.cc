// https://open.kattis.com/problems/lawnmower
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int x, y;
    double w;
    cin >> x >> y >> w;
    if (!x && !y && !w) break;
    vector<double> xs(x), ys(y);
    for (int i = 0; i < x; i++) cin >> xs[i];
    for (int i = 0; i < y; i++) cin >> ys[i];
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    double cx = 0, cy = 0;
    bool ok = 1;
    for (double xi : xs) {
      if (xi - w / 2 > cx) {
        ok = 0;
        break;
      }
      cx = xi + w / 2;
    }
    for (double yi : ys) {
      if (yi - w / 2 > cy) {
        ok = 0;
        break;
      }
      cy = yi + w / 2;
    }
    if (cx < 75 || cy < 100) ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
  }
}
