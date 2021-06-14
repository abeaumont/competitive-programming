// https://cses.fi/problemset/task/1678
#include <bits/stdc++.h>

using namespace std;

vector<int> s;
vector<vector<int>> g;
vector<int> ans;

bool dfs(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v]) {
      if (dfs(v)) {
        if (ans[0] != ans.back()) ans.push_back(u);
        return true;
      }
    } else if (s[v] == 1) {
      ans.push_back(v);
      ans.push_back(u);
      return true;
    }
  s[u] = 2;
  return false;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vector<vector<int>>(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  s = vector<int>(n);
  for (int i = 0; i < n; i++)
    if (!s[i])
      if (dfs(i)) {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
          cout << ans[ans.size() - i - 1] + 1 << " \n"[i == ans.size() - 1];
        return 0;
      }
  cout << "IMPOSSIBLE\n";
}
