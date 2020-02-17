// https://open.kattis.com/problems/closestsums
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t = 0, n, m, x, r, M;
  while (++t) {
    cin >> n;
    if (cin.eof()) return 0;
    cout << "Case " << t << ":\n";
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    while (m--) {
      cin >> x;
      M = 1e9;
      for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
          if (abs(a[i]+a[j]-x) < M)
            r = a[i]+a[j], M = abs(r-x);
      cout << "Closest sum to " << x << " is " << r << ".\n";
    }
  }
}
