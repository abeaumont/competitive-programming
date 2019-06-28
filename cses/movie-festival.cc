// https://cses.fi/problemset/task/1629/
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y, c = 0, s = 0;
  cin >> n;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[i] = {y, x};
  }
  sort(a.begin(), a.end());
  for (ii z : a) {
    tie(y, x) = z;
    if (x >= s) s = y, c++;
  }
  cout << c << "\n";
}
