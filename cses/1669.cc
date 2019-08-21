// https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi s, r;

bool dfs(int u, int p) {
  s[u] = 1;
  r.push_back(u);
  for (int v : g[u]) {
    if (s[v] && u != v && p != v) {
      r.push_back(v);
      return 1;
    }
    if (!s[v] && dfs(v, u)) return 1;
  }
  r.pop_back();
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  s = vi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!s[i]) {
      r = vi();
      if (dfs(i, -1)) {
        int k = r.back();
        int i = 0;
        while (r[i] != k) i++;
        cout << r.size() - i << "\n";
        for (; i < r.size(); i++)
          cout << r[i] + 1 << " \n"[i == r.size() - 1];
        return 0;
      }
    }
  cout << "IMPOSSIBLE\n";
}
