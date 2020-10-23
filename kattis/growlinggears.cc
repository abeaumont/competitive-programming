// https://open.kattis.com/problems/growlinggears
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    double a, b, c, t, mt = 0;
    int g = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a >> b >> c;
      t = b * b / (4 * a) + c;
      if (t > mt) mt = t, g = i;
    }
    cout << g << '\n';
  }
}
