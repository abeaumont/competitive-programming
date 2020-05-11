// https://codeforces.com/contest/1012/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n, m;
vvi g;
vi s;

void dfs(int u) {
  s[u] = 1;
  for (int v:g[u])
    if (!s[v])
      dfs(v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, q, r, c;
  cin >> n >> m >> q;
  g = vvi(n+m);
  for (int i = 0; i < q; i++) {
    cin >> r >> c;
    r--, c--;
    g[r].push_back(c+n);
    g[c+n].push_back(r);
  }
  s = vi(n+m);
  int k = 0;
  for (int i = 0; i < n+m; i++)
    if (!s[i])
      k++, dfs(i);
  cout << k-1 << '\n';
}
