// https://cses.fi/problemset/task/1653
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  vector<pair<int, int>> best(1 << n, {n + 1, 0});
  best[0] = {1, 0};
  for (int s = 1; s < (1 << n); s++)
    for (int p = 0; p < n; p++)
      if (s & (1 << p)) {
        auto b = best[s ^ (1 << p)];
        if (b.second + w[p] <= x) b.second += w[p];
        else
          b = {b.first + 1, w[p]};
        best[s] = min(best[s], b);
      }
  cout << best[(1 << n) - 1].first << '\n';
}
