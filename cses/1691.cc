// https://cses.fi/problemset/task/1691
#include <bits/stdc++.h>

using namespace std;

using si = unordered_set<int>;
using qi = queue<int>;
using vb = vector<bool>;
using vi = vector<int>;
using vsi = vector<si>;
using vvi = vector<vi>;

vb s;
vi vs;
vsi g;
vvi paths;
qi q;
int k = 1;

void dfs1(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v])
      dfs1(v);
}

void dfs2(int u) {
  if (!s[u]) {
    q.push(u);
    s[u] = 1;
  }
  paths.back().push_back(u);
  if (g[u].size()) {
    int v = *g[u].begin();
    g[u].erase(v);
    g[v].erase(u);
    dfs2(v);
  }
}

void circuits(int i) {
  for (int x : paths[i])
    if (k < vs.size() && x == vs[k]) {
      k++;
      circuits(k - 1);
    } else
      cout << x + 1 << " ";
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  g = vsi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  s = vb(n);
  dfs1(0);
  for (int i = 0; i < n; i++)
    if ((!s[i] && g[i].size()) || g[i].size() % 2) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  s = vb(n);
  s[0] = 1;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    while (g[i].size()) {
      vs.push_back(i);
      paths.push_back(vi());
      dfs2(i);
    }
  }
  circuits(0);
  cout << endl;
}
