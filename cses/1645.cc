// https://cses.fi/problemset/task/1645
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

int main() {
  int n, x, y;
  cin >> n;
  vi a(n);
  vii b;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    while (!b.empty()) {
      tie(x, y) = b.back();
      if (y < a[i]) break;
      b.pop_back();
    }
    if (b.empty()) x = 0;
    cout << x << " \n"[i == n - 1];
    b.push_back({i + 1, a[i]});
  }
}
