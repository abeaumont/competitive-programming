// https://open.kattis.com/problems/convexpolygonarea
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, x0, y0, x1, y1, x2, y2;
  cin >> t;
  while (t--) {
    cin >> n;
    double s = 0;
    cin >> x0 >> y0 >> x1 >> y1;
    s += x0 * y1 - x1 * y0;
    for (int i = 2; i < n; i++) {
      cin >> x2 >> y2;
      s += x1 * y2 - x2 * y1;
      x1 = x2, y1 = y2;
    }
    s += x2 * y0 - x0 * y2;
    cout << setprecision(10) << s / 2 << "\n";
  }
}
