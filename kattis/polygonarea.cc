// https://open.kattis.com/problems/polygonarea
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (1) {
    int n, x0, y0, x1, y1, x2, y2;
    cin >> n;
    if (!n) break;
    double s = 0;
    cin >> x0 >> y0 >> x1 >> y1;
    s += x0 * y1 - x1 * y0;
    for (int i = 2; i < n; i++) {
      cin >> x2 >> y2;
      s += x1 * y2 - x2 * y1;
      x1 = x2, y1 = y2;
    }
    s += x2 * y0 - x0 * y2;
    cout << setprecision(1) << fixed << (s > 0 ? "CCW " : "CW ") << fabs(s) / 2 << "\n";
  }
}
