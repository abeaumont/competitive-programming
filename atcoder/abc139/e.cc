// https://atcoder.jp/contests/abc139/tasks/abc139_e
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, u, v;
  cin >> n;
  vi a(n * n), d(n * n);
  vvi g(n * n);
  for(int i = 0; i < n; i++) {
    int p;
    for (int j = 0; j < n - 1; j++) {
      cin >> u, u--;
      int e;
      if (i > u) e = u * n + i;
      else e = i * n + u;
      if (j) g[p].push_back(e), a[e]++;
      p = e;
    }
  }
  bool ok = 1;
  qi q;
  for (int i = 0; i < n * n; i++)
    if (!a[i])
      q.push(i), d[i] = 1;
  while (ok && !q.empty()) {
    u = q.front();
    q.pop();
    for(int v : g[u]) {
      a[v]--;
      if (!a[v])
        q.push(v), d[v] = d[u] + 1;
    }
  }
  for (int x : a)
    if (x) {
      cout << "-1\n";
      return 0;
    }
  cout << d[u] << "\n";
}
