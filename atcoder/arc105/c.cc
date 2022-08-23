// https://atcoder.jp/contests/arc105/tasks/arc105_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int M = 1e5;
ll n, m, l[M], v[M];

ll solve(vector<ll> w) {
  vector<ll> pos(n);
  for (int i = 1; i < n; i++) {
    ll mx = 0;
    for (int j = 0; j < m; j++) {
      ll s = w[i];
      for (int k = i - 1; k >= 0; k--) {
        if (pos[k] > mx - l[j] && s + w[k] > v[j]) {
          mx = pos[k] + l[j];
          break;
        }
        if (pos[k] + l[j] <= mx) break;
        s += w[k];
      }
    }
    pos[i] = mx;
  }
  return pos[n - 1];
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  vector<ll> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < m; i++) cin >> l[i] >> v[i];
  bool ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (w[i] > v[j]) ok = 0;
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  sort(w.begin(), w.end());
  swap(w[0], w[n - 2]);
  ll best = solve(w);
  swap(w[0], w[n - 2]);
  while (next_permutation(w.begin(), w.begin() + n - 2)) {
    swap(w[0], w[n - 2]);
    best = min(best, solve(w));
    swap(w[0], w[n - 2]);
  }
  cout << best << '\n';
}
