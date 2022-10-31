// https://open.kattis.com/problems/flyingsafely
#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int sz[N], p[N];

int find(int u) {
  if (p[u] != u) p[u] = find(p[u]);
  return p[u];
}

int unite(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return 0;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, u, v, c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      u--, v--;
      c += unite(u, v);
    }
    cout << c << '\n';
  }
}
