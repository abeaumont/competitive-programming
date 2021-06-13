// https://atcoder.jp/contests/abc199/tasks/abc199_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio();
  int n, mn = 1001, mx = -1, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mx = max(mx, x);
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    mn = min(mn, x);
  }
  if (mx > mn) cout << "0\n";
  else
    cout << mn - mx + 1 << '\n';
}
