// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5;
ll f[N], a[N], b[N], s[N];
vector<int> g[N];

void dfs(int u) {
  s[u] = 1;
  int c = 0;
  for (int v : g[u])
    if (v > u) dfs(v), c++;
  if (!c) {
    a[u] = f[u];
    b[u] = 0;
  } else {
    ll mn = 1e18, k;
    for (int v : g[u])
      if (v > u && a[v] < mn) mn = a[v], k = v;
    for (int v : g[u])
      if (v > u && v != k) b[u] += a[v] + b[v];
    b[u] += b[k];
    a[u] = max(a[k], f[u]);
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int T, n;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> f[i];
    fill(a, a + n, 0);
    fill(b, b + n, 0);
    fill(s, s + n, 0);
    fill(g, g + n, vector<int>());
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (!p) continue;
      p--;
      g[i].push_back(p);
      g[p].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
      if (!s[i]) {
        dfs(i);
        ans += a[i] + b[i];
      }
    cout << "Case #" << t << ": " << ans << '\n';
  }
}
