// https://open.kattis.com/problems/equivalences
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int c;
vi a, s;
vvi g, h;

void dfs1(int i) {
  s[i] = 1;
  for (int j : g[i])
    if (!s[j]) dfs1(j);
  a.push_back(i);
}

void dfs2(int i) {
  s[i] = c;
  for (int j : h[i])
    if (!s[j]) dfs2(j);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    g = vvi(n), h = vvi(n);
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      h[v].push_back(u);
    }
    a.clear(), s = vi(n);
    for (int i = 0; i < n; i++)
      if (!s[i]) dfs1(i);
    reverse(a.begin(), a.end());
    fill(s.begin(), s.end(), 0);
    c = 0;
    for (int i = 0; i < a.size(); i++)
      if (!s[a[i]]) c++, dfs2(a[i]);
    if (c == 1) cout << "0\n";
    else {
      vi in(c), out(c);
      for (int i = 0; i < n; i++)
        for (int j : g[i])
          if (s[i] != s[j]) in[s[j] - 1]++, out[s[i] - 1]++;
      int c1 = 0, c2 = 0;
      for (int i = 0; i < c; i++) c1 += in[i] == 0, c2 += out[i] == 0;
      cout << max(c1, c2) << '\n';
    }
  }
}
