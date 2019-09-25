// https://cses.fi/problemset/task/1679
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vi p, s;
vvi g;

bool dfs(int u) {
  s[u] = 1;
  for(int v : g[u])
    if (s[v] == 1 || !s[v] && !dfs(v)) return 0;
  s[u] = 2;
  p.push_back(u);
  return 1;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vvi(n);
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  s = vi(n);
  for (int i = 0; i < n; i++)
    if(!s[i])
      if (!dfs(i)) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
  reverse(p.begin(), p.end());
  for(int i = 0; i < n; i++)
    cout << p[i] + 1 << " \n"[i == n - 1];
}
