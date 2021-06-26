// https://cses.fi/problemset/task/1693
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> g;
vector<int> s, ans;
vector<vector<int>> cc;
vector<set<int>> ci;

void dfs1(int u = 0) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v]) dfs1(v);
}

void dfs2(int c) {
  for (int u : cc[c]) {
    if (ans.empty() || ans.back() != u) ans.push_back(u);
    while (!ci[u].empty()) {
      auto it = ci[u].begin();
      ci[u].erase(it);
      dfs2(*it);
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  vector<pair<int, int>> e(m);
  g = vector<set<int>>(n);
  vector<int> in(n), out(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    e[i] = {u, v};
    g[u].insert(v);
    out[u]++, in[v]++;
  }
  if (in[0] != out[0] - 1 && in[n - 1] != out[n - 1] - 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int i = 1; i < n - 1; i++)
    if (in[i] != out[i]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  s = vector<int>(n);
  dfs1();
  for (int i = 0; i < n; i++)
    if (!s[i] && !g[i].empty()) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  g[n - 1].insert(0);
  s = vector<int>(n);
  queue<int> q;
  q.push(0);
  s[0] = 1;
  ci = vector<set<int>>(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    while (g[u].begin() != g[u].end()) {
      ci[u].insert(cc.size());
      cc.push_back(vector<int>(1, u));
      int v;
      do {
        if (g[u].begin() == g[u].end()) break;
        int v = *g[u].begin();
        if (!s[v]) s[v] = 1, q.push(v);
        g[u].erase(v);
        cc.back().push_back(v);
        u = v;
      } while (u != cc.back()[0]);
    }
  }
  while (!ci[0].empty()) {
    auto it = ci[0].begin();
    ci[0].erase(it);
    dfs2(*it);
  }
  int k;
  for (int i = 0; i <= m; i++)
    if (ans[i] == n - 1 && ans[i + 1] == 0) {
      k = i;
      break;
    }
  for (int i = k + 1; i <= m; i++) cout << ans[i] + 1 << ' ';
  for (int i = 0; i <= k; i++) cout << ans[i] + 1 << " \n"[i == k];
}
