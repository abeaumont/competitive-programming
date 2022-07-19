// https://atcoder.jp/contests/abc165/tasks/abc165_f
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5, INF = 1e9;
int a[N], ans[N], n;
vector<int> g[N], d;

void dfs(int u, int p = -1) {
  int i = upper_bound(d.begin(), d.end(), a[u]) - d.begin();
  int t = d[i];
  if (d[i - 1] < a[u] && a[u] < d[i]) d[i] = a[u];
  ans[u] = lower_bound(d.begin(), d.end(), INF) - d.begin() - 1;
  for (int v : g[u])
    if (v != p) dfs(v, u);
  d[i] = t;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  d = vector<int>(n + 1, INF);
  d[0] = -INF;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}
