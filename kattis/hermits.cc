// https://open.kattis.com/problems/hermits
#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
int a[N];
vector<int> g[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int mx = 1e9 + 1, mxu;
  for (int u = 0; u < n; u++) {
    int sum = a[u];
    for (int v : g[u]) sum += a[v];
    if (sum < mx) mx = sum, mxu = u;
  }
  cout << mxu + 1 << '\n';
}
