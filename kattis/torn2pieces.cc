// https://open.kattis.com/problems/torn2pieces
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = unordered_map<string, int>;

int c;
vi vis, p;
vvi g;

void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) {
      p[v] = u;
      dfs(v);
    }
}

int main() {
  int n, c = 0;
  string s, t;
  cin >> n;
  getline(cin, s);
  vii e;
  msi m;
  vs mi;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    stringstream in(s);
    in >> t;
    if (!m.count(t)) {
      m[t] = c++;
      mi.push_back(t);
    }
    int u = m[t];
    while (in >> t) {
      if (!m.count(t)) {
        m[t] = c++;
        mi.push_back(t);
      }
      int v = m[t];
      e.push_back({u, v});
    }
  }
  cin >> s >> t;
  if (!m.count(s) || !m.count(t)) {
    cout << "no route found\n";
    return 0;
  }
  int a = m[s], b = m[t];
  g = vvi(c);
  for (auto [u, v] : e) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  p = vi(c, -1), vis = vi(c);
  dfs(b);
  if (p[a] < 0) cout << "no route found\n";
  else {
    vi path(1, a);
    int u = a;
    while (u != b) {
      u = p[u];
      path.push_back(u);
    }
    for (int i = 0; i < path.size(); i++)
      cout << mi[path[i]] << " \n"[i == path.size() - 1];
  }
}
