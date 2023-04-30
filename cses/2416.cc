// https://cses.fi/problemset/task/2416
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5, INF = 2 * N, K = 450;
ll x[N + 1], p[N + 1], ni[N + 1], ci[N + 1], c[K + 1][N + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, q, a, b;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> x[i], p[i] = x[i] + p[i - 1];
  vector<pair<int, int>> s;
  for (int i = n; i; i--) {
    while (!s.empty() && s.back().first < x[i]) s.pop_back();
    if (s.empty()) ni[i] = INF;
    else
      ni[i] = s.back().second;
    s.push_back({x[i], i});
  }
  for (int l = 1, k = 1, j = 1; l <= n; l++)
    if (ni[l] >= k && ni[l] <= n) {
      k += K;
      a = ni[l];
      ci[a] = j;
      ll mn = x[a];
      while (a <= n) mn = max(mn, x[a]), c[j][a] = c[j][a - 1] + mn - x[a], a++;
      j++;
    }
  while (q--) {
    cin >> a >> b;
    ll mn = x[a], s = 0, i = a;
    while (!ci[i] && ni[i] <= b) {
      while (ni[i] <= b && !ci[ni[i]] && x[ni[i]] <= mn) i = ni[i];
      i = min(b, ni[i]);
      s += mn * (i - a - 1) - (p[i - 1] - p[a]);
      mn = max(mn, x[i]), a = i;
    }
    if (ci[a]) {
      s += c[ci[a]][b] - c[ci[a]][a - 1];
      if (mn > x[a]) s += (b - a + 1) * (mn - x[a]);
    } else
      s += mn * (b - a + 1) - (p[b] - p[a - 1]);
    cout << s << '\n';
  }
}
