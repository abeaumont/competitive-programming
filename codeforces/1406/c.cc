// https://codeforces.com/contest/1406/problem/C
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vvi g;
vi d;

void dfs(int u, int p) {
  d[u] = 1;
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      d[u] += d[v];
    }
}

tuple<int, int> find_leave(int u, int p) {
  if (g[u].size() == 1) return {u, p};
  for (int v : g[u])
    if (v != p) return find_leave(v, u);
  assert(false);
  return {0, 0};
}

void find(int u, int p) {
  int mx = 0, k;
  for (int v : g[u])
    if (v != p && d[v] > mx) mx = d[v], k = v;
  if (mx < n / 2) {
    for (int i = 0; i < 2; i++) cout << u + 1 << ' ' << k + 1 << '\n';
    return;
  }
  if (mx == n / 2) {
    int p, q;
    tie(p, q) = find_leave(k, u);
    cout << q + 1 << ' ' << p + 1 << '\n';
    cout << u + 1 << ' ' << p + 1 << '\n';
    return;
  }
  find(k, u);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, u, v;
  cin >> t;
  while (t--) {
    cin >> n;
    g = vvi(n);
    d = vi(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (n % 2) {
      for (int i = 0; i < 2; i++) cout << u + 1 << ' ' << v + 1 << '\n';
      continue;
    }
    dfs(0, -1);
    find(0, -1);
  }
}
