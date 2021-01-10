// https://open.kattis.com/problems/unfairplay
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using qi = queue<int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using mii = map<int, int>;

int k, flow;
vi l, p;
vvi c;

bool dfs(int u, int f) {
  if (u == k - 1) {
    flow += f;
    while (u != k - 2) {
      c[p[u]][u] -= f;
      c[u][p[u]] += f;
      u = p[u];
    }
    return 1;
  }
  for (int v = 0; v < k; v++) {
    if (l[v] == l[u] + 1 && c[u][v] > 0) {
      p[v] = u;
      if (dfs(v, min(c[u][v], f))) return 1;
    }
  }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, m, u, v, C = 0;
    cin >> n;
    if (n < 0) break;
    cin >> m;
    vi ps(n);
    for (int i = 0; i < n; i++) cin >> ps[i];
    mii gxy, ei;
    vi rei(m, -1);
    vii e;
    for (int i = 0; i < m; i++) {
      cin >> u >> v, u--, v--;
      e.push_back({u, v});
      if (v < u) swap(u, v);
      if (v == n - 1) ps[n - 1] += 2;
      else {
        int j = u * n + v;
        gxy[j]++;
        if (!ei.count(j)) ei[j] = ei.size();
        rei[i] = ei[j];
      }
    }
    k = n + gxy.size() + 1;
    c = vvi(k, vi(k));
    for (int i = 0; i < m; i++) {
      int j = rei[i];
      if (j < 0) continue;
      tie(u, v) = e[i];
      C += 2;
      c[k - 2][n + j - 1] += 2;
      c[n + j - 1][u] += 2;
      c[n + j - 1][v] += 2;
    }
    bool ok = 1;
    for (int i = 0; i < n - 1; i++) {
      int w = ps[n - 1] - ps[i] - 1;
      if (w < 0) {
        ok = 0;
        break;
      }
      c[i][k - 1] = w;
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }

    flow = 0;
    while (1) {
      l = vi(k, -1);
      qi q;
      q.push(k - 2);
      l[k - 2] = 0;
      while (!q.empty()) {
        u = q.front();
        if (u == k - 1) break;
        q.pop();
        for (int v = 0; v < k; v++)
          if (l[v] < 0 && c[u][v] > 0) l[v] = l[u] + 1, q.push(v);
      }
      if (q.empty()) break;
      p = vi(k);
      while (dfs(k - 2, 1e9))
        ;
    }
    if (C > flow) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < m; i++) {
      tie(u, v) = e[i];
      if (u == n - 1) cout << 0;
      else if (v == n - 1)
        cout << 2;
      else {
        int w = n + rei[i] - 1;
        if (c[u][w] >= 2) c[u][w] -= 2, cout << 0;
        else if (c[u][w])
          c[u][w]--, cout << 1;
        else
          cout << 2;
      }
      cout << " \n"[i == m - 1];
    }
  }
}
