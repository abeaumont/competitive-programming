// https://open.kattis.com/problems/paintball
#include <bits/stdc++.h>

using namespace std;
using qi = queue<int>;
using vi = vector<int>;

const int N = 2002;

int n, l[N], p[N];
int g[N][N];

bool dfs(int u) {
  if (u == 2 * n + 1) {
    while (u) g[p[u]][u]--, g[u][p[u]]++, u = p[u];
    return 1;
  }
  for (int v = 0; v <= 2 * n + 1; v++)
    if (l[v] == l[u] + 1 && g[u][v]) {
      p[v] = u;
      if (dfs(v)) return 1;
    }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, u, v;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[0][i]++;
    g[n + i][2 * n + 1]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u][n + v]++;
    g[v][n + u]++;
  }
  while (1) {
    fill(l, l + 2 * n + 2, -1);
    qi q;
    q.push(0);
    l[0] = 0;
    while (!q.empty()) {
      u = q.front();
      if (u == 2 * n + 1) break;
      q.pop();
      for (int v = 0; v <= 2 * n + 1; v++)
        if (l[v] < 0 && g[u][v]) l[v] = l[u] + 1, q.push(v);
    }
    if (q.empty()) break;
    while (dfs(0))
      ;
  }
  vi e;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (g[n + j][i]) {
        e.push_back(j);
        break;
      }
  if (e.size() < n) {
    cout << "Impossible\n";
    return 0;
  }
  for (int u : e) cout << u << '\n';
}
