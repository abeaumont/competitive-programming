// https://open.kattis.com/problems/3dprinter
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mn = 1000000;
  for (int i = 0; i <= n; i++) {
    int p = 1, s = n, d = 0;
    while (s > 0) {
      int k = min(p, i + 1 - p);
      s -= p - k;
      p += k;
      d++;
    }
    mn = min(mn, d);
  }
  cout << mn << '\n';
}
