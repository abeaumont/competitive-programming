// https://open.kattis.com/problems/maxcolinear
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int n, x, y;
    cin >> n;
    if (!n) break;
    vii a(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      a[i] = {x, y};
    }
    int m = 1;
    for (int i = 0; i < n; i++) {
      int x0, y0, x1, y1;
      tie(x0, y0) = a[i];
      for (int j = i + 1; j < n; j++) {
        int c = 2;
        tie(x1, y1) = a[j];
        int x = x1 - x0, y = y1 - y0;
        for (int k = j + 1; k < n; k++) {
          tie(x1, y1) = a[k];
          if (!(x * (y1 - y0) - (x1 - x0) * y)) c++;
        }
        if (c > m) m = c;
      }
    }
    cout << m << "\n";
  }
}
