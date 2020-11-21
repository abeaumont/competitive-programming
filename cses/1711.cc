// https://cses.fi/problemset/task/1711/
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using qi = queue<int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int N = 500;

int n, l[N + 1], p[N + 1];
int g[N + 1][N + 1], go[N + 1][N + 1];
vvi ans;

bool dfs(int u) {
  if (u == n - 1) {
    while (u) g[p[u]][u]--, g[u][p[u]]++, u = p[u];
    return 1;
  }
  for (int v = 0; v < n; v++)
    if (l[v] == l[u] + 1 && g[u][v]) {
      p[v] = u;
      if (dfs(v)) return 1;
    }
  return 0;
}

bool dfs2(int u) {
  if (u == n - 1) {
    ans.push_back(vi());
    while (u) ans.back().push_back(u), u = p[u];
    ans.back().push_back(0);
    reverse(ans.back().begin(), ans.back().end());
    return 1;
  }
  for (int v = 0; v < n; v++)
    if (go[u][v] && !g[u][v]) {
      p[v] = u, go[u][v] = 0;
      if (dfs2(v)) return 1;
    }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    go[u][v]++;
    g[u][v]++;
  }
  while (true) {
    fill(l, l + n, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == n - 1) break;
      q.pop();
      for (int v = 0; v < n; v++)
        if (l[v] < 0 && g[u][v]) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0))
      ;
  }
  fill(l, l + n, -1);
  while (dfs2(0))
    ;
  cout << ans.size() << '\n';
  for (auto &r : ans) {
    cout << r.size() << '\n';
    for (int i = 0; i < r.size(); i++)
      cout << r[i] + 1 << " \n"[i == r.size() - 1];
  }
}
