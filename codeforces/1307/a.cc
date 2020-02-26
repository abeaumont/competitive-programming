// https://codeforces.com/problemset/problem/1307/A
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, d;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = a[0];
    for (int i = 1; i < n; i++) {
      if (i*a[i] <= d) {
        sum += a[i];
        d -= i*a[i];
        continue;
      }
      sum += d/i;
      break;
    }
    cout << sum << '\n';
  }
}
