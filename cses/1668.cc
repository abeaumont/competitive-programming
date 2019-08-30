// https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>

using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;
using qi=queue<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  vvi g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi c(n);
  bool ok = 1;
  for (int i = 0; i < n; i++)
    if (!c[i]) {
      qi q;
      q.push(i);
      c[i] = 1;
      while (!q.empty()) {
        u = q.front();
        int z = c[u] % 2 + 1;
        q.pop();
        for (int v : g[u])
          if (!c[v]) q.push(v), c[v] = z;
          else if (z != c[v]) {
            ok = 0;
            break;
          }
      }
    }
  if(!ok) {
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
    cout << c[i] << " \n"[i == n - 1];
}
