// https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi s;
vvi g;
int n;

void dfs(int u) {
  s[u] = 1;
  for (int v : g[u])
    if (!s[v])
      dfs(v);
}

int main() {
  int m, u, v;
  cin >> n >> m;
  g = vvi(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  s = vi(n);
  vi b;
  dfs(0);
  for (int i = 1; i < n; i++)
    if (!s[i]) {
      b.push_back(i);
      dfs(i);
    }
  cout << b.size() << endl;
  for (int x : b)
    cout << 1 << " " << x + 1 << endl;
}
