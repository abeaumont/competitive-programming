// https://codeforces.com/contest/1228/problem/A
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using si = unordered_set<int>;
using vsi = vector<si>;
using vvi = vector<vi>;
using qi = queue<int>;

int n, k, r, s = -1;
vi d, depth;
vsi h;
vvi g;

bool dfs(int u, int p) {
  if (p == -1 && (d[u] != 2 && d[u] != 3)) return 0;
  if (p == -1 && d[u] == 3) {
    if (r) return 0;
    r = u + 1;
    int c = 0;
    for (int v : g[u]) {
      if (depth[v] == depth[u] - 1) s = v + 1;
      else if (depth[v] == depth[u] - 2) c++;
    }
    if (c != 2 || s == -1) return 0;
  }
  if (p >= 0 && d[u] == 4 && depth[u] > 1) {
    if (r) return 0;
    r = u + 1;
  }
  if (p >= 0 && d[u] == 2 && depth[u] > 1) return 0;
  if (p >= 0 && d[u] == 2 && depth[u] == 1) {
    if (r) return 0;
    r = u + 1;
  }
  bool ok = 1;
  for (int v : g[u])
    if (v != p) {
      if (r != u + 1 && depth[v] + 1 != depth[u]) ok = 0;
      if (!dfs(v, u)) ok = 0;
    }
  return ok;
}

int main() {
  int n, u, v;
  cin >> n;
  if (n == 2) {
    cout << "2\n1 2\n";
    return 0;
  }
  int k = 1;
  for (int i = 0; i < n; i++) k *= 2;
  k -= 2;
  g = vvi(k), h = vsi(k);
  for (int i = 0; i < k - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    h[u].insert(v);
    h[v].insert(u);
  }
  vi c(5);
  d = vi(k), depth = vi(k);
  qi q;
  for (int i = 0; i < k; i++) {
    d[i] = g[i].size();
    if (d[i] >= 1 && d[i] <= 4) c[d[i]]++;
    else c[0]++;
    if (d[i] == 1) {
      q.push(i);
      depth[i] = 0;
    }
  }
  int l = (k + 2) / 2;
  if (c[0] || c[4] > 1 || (c[1] != l && c[1] != l - 1)) {
    cout << "0\n";
    return 0;
  }
  vi p(k, -1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (h[u].empty()) continue;
    int v = *h[u].begin();
    p[u] = v;
    depth[v] = max(depth[u], depth[u] + 1);
    h[v].erase(u);
    if (h[v].size() == 1) q.push(v);
  }
  int root = -1;
  for (int i = 0; i < k; i++)
    if (p[i] == -1) {
      if (root == -1) root = i;
      else {
        cout << "0\n";
        return 0;
      }
    }
  if (root == -1) {
    cout << "0\n";
    return 0;
  }
  if (dfs(root, -1)) {
    if (s >= 0) cout << "2\n" << min(r, s) << " " << max(r, s) << "\n";
    else cout << "1\n" << r << "\n";
  } else cout << "0\n";
}
