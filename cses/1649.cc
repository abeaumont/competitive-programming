// https://cses.fi/problemset/task/1649/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k = 1, n, q, x, y, z;
  cin >> n >> q;
  while (k < n) k *= 2;
  vector<int> a(2 * k, 2e9);
  for (int i = 0; i < n; i++) cin >> a[k + i];
  for (int i = k - 1; i; i--) a[i] = min(a[2 * i], a[2 * i + 1]);
  while (q--) {
    cin >> x >> y >> z;
    if (x == 1) {
      y += k - 1;
      a[y] = z;
      for (y /= 2; y; y /= 2) a[y] = min(a[y * 2], a[y * 2 + 1]);
    } else {
      y += k - 1, z += k - 1;
      int m = 1e9;
      while (y <= z) {
        if (y & 1) m = min(m, a[y++]);
        if (!(z & 1)) m = min(m, a[z--]);
        y /= 2, z /= 2;
      }
      cout << m << "\n";
    }
  }
}
