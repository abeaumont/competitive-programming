// https://codeforces.com/contest/1300/problem/D
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x, y;
  cin >> n;
  vector<tuple<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p[i] = {x, y};
  }
  if (n % 2 == 1) {
    cout << "NO\n";
    return 0;
  }
  int x1, y1, x2, y2, cx2, cy2;
  tie(x1, y1) = p[0];
  tie(x2, y2) = p[n/2];
  cx2 = x1 + x2, cy2 = y1 + y2;
  for (int i = 1; i < n/2; i++) {
    tie(x1, y1) = p[i];
    tie(x2, y2) = p[n/2+i];
    if ((x1 + x2 != cx2) || (y1 + y2 != cy2)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
