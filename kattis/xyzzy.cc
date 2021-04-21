// https://open.kattis.com/problems/xyzzy
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, q, u, v, w;
    cin >> n;
    if (n < 0) break;
    vector<tuple<int, int, int>> e;
    for (int i = 0; i < n; i++) {
      cin >> w >> q;
      while (q--) {
        cin >> v, v--;
        e.push_back({i, v, -w});
      }
    }
    vector<int> d(n, 2e9);
    d[0] = -100;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        for (auto x : e) {
          tie(u, v, w) = x;
          if (d[u] < 0) d[v] = min(d[v], d[u] + w);
        }
      }
      if (d[n - 1] < 0) break;
      vector<int> d2 = d;
      for (auto x : e) {
        tie(u, v, w) = x;
        if (d2[u] < 0) d2[v] = min(d2[v], d2[u] + w);
      }
      bool ok = 1;
      for (int i = 0; i < n; i++)
        if (d[i] > -1e6 && d2[i] < d[i]) ok = 0, d[i] = -1e6;
      if (ok) break;
    }
    if (d[n - 1] < 0) cout << "winnable\n";
    else
      cout << "hopeless\n";
  }
}
