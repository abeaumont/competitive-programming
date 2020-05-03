#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  int c, n;
  cin >> c;
  for (int t = 1; t <= c; t++) {
    int n = 0, m, u, v, r;
    cin >> m;
    vii e(m);
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> r;
      n = max(n, max(u, v));
      u--, v--;
      e[i] = r ? make_tuple(u, v) : make_tuple(v, u);
    }
    vvi g(n);
    for (ii z : e) {
      tie(u, v) = z;
      g[u].push_back(v);
    }
    vi s(n), p;
    function<void(int)>dfs = [&](int u){
      s[u] = 1;
      for (int v : g[u])
        if (!s[v])
          dfs(v);
      p.push_back(u);
    };
    for (int i = 0; i < n; i++)
      if (!s[i])
        dfs(i);
    printf("Case #%d: %d\n", t, p[n-1]+1);
  }
}
