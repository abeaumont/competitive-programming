// https://cses.fi/problemset/task/1678
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;

vvi g;
vi r, s;
si t;

bool dfs(int u) {
  s[u] = 1;
  t.insert(u);
  for (int v : g[u]) {
    if (t.count(v)) {
      r.push_back(v);
      return true;
    }
    if (!s[v]) {
      r.push_back(v);
      if (dfs(v)) return true;
      r.pop_back();
    }
  }
  return false;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v);
  }
  s = vi(n);
  for (int i = 0; i < n; i++) {
    if (!s[i]) {
      t = si();
      r = vi(1, i);
      if (dfs(i)) {
        reverse(r.begin(), r.end());
        while (r.back() != r.front()) r.pop_back();
        if (r.size() <= 2) continue;
        reverse(r.begin(), r.end());
        cout << r.size() << '\n';
        for (int j = 0; j < r.size(); j++)
          cout << r[j]+1 << " \n"[j == r.size() - 1];
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

