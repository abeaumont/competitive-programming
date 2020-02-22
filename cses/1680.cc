// https://cses.fi/problemset/task/1680
#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi s, p, dp, q;

void dfs(int u) {
  s[u]=1;
  for(int v:g[u])
    if(!s[v])
      dfs(v);
  p.push_back(u);
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  s = vi(n), dp = vi(n, -1), q = vi(n);;
  for(int i=0;i<n;i++)
    if(!s[i])
      dfs(i);
  reverse(p.begin(), p.end());
  for(int i = 0; i < n; i++) {
    u = p[i];
    if (u == n-1) break;
    if (!u) dp[u] = 1;
    if (dp[u] > 0)
      for (int v : g[u])
        if (dp[v] < dp[u] + 1) dp[v] = dp[u]+1, q[v] = u;
  }
  if (dp[n-1] < 0) cout << "IMPOSSIBLE\n";
  else {
    vi r(1, n);
    int u = n-1;
    while (u) u = q[u], r.push_back(u+1);
    reverse(r.begin(), r.end());
    cout << r.size() << '\n';
    for (int i = 0; i < r.size(); i++)
      cout << r[i] << " \n"[i == r.size()-1];
  }
}
