// https://cses.fi/problemset/view/1711/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using si = unordered_set<int>;
using vvi = vector<vi>;
using vsi = vector<si>;
using qi = queue<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  vsi g(n);
  vvi r;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].insert(v);
  }
  while (true) {
    vi p(n), s(n);
    qi q;
    q.push(0);
    p[0] = -1;
    s[0] = true;
    bool ok = false;
    while (!q.empty()) {
      u = q.front();
      q.pop();
      if (u == n - 1) {
        ok = true;
        r.push_back(vi());
        do {
          if (p[u] >= 0) g[p[u]].erase(u);
          r.back().push_back(u);
          u = p[u];
        } while (u != -1);
        break;
      }
      for (int v : g[u])
        if (!s[v]) {
          p[v] = u;
          s[v] = true;
          q.push(v);
        }
    }
    if (!ok) break;
  }
  cout << r.size() << "\n";
  for (vi &x : r) {
    reverse(x.begin(), x.end());
    cout << x.size() << "\n";
    for (int i = 0; i < x.size(); i++)
      cout << x[i] + 1 << " \n"[i == x.size() - 1];
  }
}
