// https://open.kattis.com/problems/collapse
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k, s, v, u, ans = 0;
  cin >> n;
  vector<vector<tuple<int, int>>> g(n);
  vector<int> a(n), b(n, 1), t(n), c;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> k;
    for (int j = 0; j < k; j++) {
      cin >> s >> v;
      s--;
      if (s) {
        a[i] += v;
        g[s].push_back({i, v});
      }
    }
    if (a[i] < t[i]) b[i] = 0, c.push_back(i);
  }
  b[0] = 0;
  while (!c.empty()) {
    u = c.back(), c.pop_back();
    for (auto [i, v] : g[u]) {
      if (!b[i]) continue;
      a[i] -= v;
      if (a[i] < t[i]) b[i] = 0, c.push_back(i);
    }
  }
  for (int x : b) ans += x;
  cout << ans << '\n';
}
