// https://www.aceptaelreto.com/problem/statement.php?id=444
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  while (1) {
    int n, k;
    cin >> n >> k;
    if (!n) break;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = 0, c = 0, z = 0;
    bool ok = 0;
    for (int x : a) {
      if (x) {
        c++, z = 0, ok = 1;

        if (c > m) m = c;
      } else {
        if (ok) c++, z++;
        if (z > k) c = 0, ok = 0;
      }
    }
    cout << m << '\n';
  }
}
