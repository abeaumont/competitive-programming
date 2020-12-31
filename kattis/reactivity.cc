// https://open.kattis.com/problems/reactivity
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

int main() {
  int n, m, u, v;
  cin >> n >> m;
  vvi g(n);
  vi a(n), b;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    a[v]++;
  }
  qi q;
  for (int i = 0; i < n; i++)
    if (!a[i]) q.push(i);
  bool ok = 1;
  while (!q.empty()) {
    if (q.size() > 1) {
      ok = 0;
      break;
    }
    u = q.front();
    q.pop();
    b.push_back(u);
    for (int v : g[u]) {
      a[v]--;
      if (!a[v]) q.push(v);
    }
  }
  if (ok)
    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
  else
    cout << "back to the lab\n";
}
