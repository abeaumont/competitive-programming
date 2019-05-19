// https://atcoder.jp/contests/abc126/tasks/abc126_d
#include <bits/stdc++.h>

using namespace std;

using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvii = vector<vii>;

int n, u, v, w;
vi c;
vvii g;

void dfs(int u, int p) {
  for (ii &x : g[u]) {
    tie(v, w) = x;
    if (v != p) {
      if (w % 2) c[v] = !c[u];
      else c[v] = c[u];
      dfs(v, u);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  g = vvii(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(make_tuple(v, w));
    g[v].push_back(make_tuple(u, w));
  }
  c = vi(n);
  c[0] = 0;
  dfs(0, -1);
  for (int x : c) cout << x << "\n";
}
