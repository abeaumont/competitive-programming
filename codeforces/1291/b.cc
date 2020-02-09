// https://codeforces.com/contest/1291/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    int m = n+1, M = -1;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x - i < 0) m = min(m, i);
      if (x - (n - i - 1) < 0) M = max(M, i);
    }
    cout << (m - M > 1 ? "Yes\n" : "No\n");
  }
}
