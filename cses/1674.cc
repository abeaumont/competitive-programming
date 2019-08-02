// https://cses.fi/problemset/task/1674/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vi c;
vvi g;

void dfs(int u) {
  c[u]++;
  for (int v : g[u]) {
    if (!c[v])
      dfs(v);
    c[u] += c[v];
  }
}

int main() {
  int x;
  cin >> n;
  c = vi(n);
  g = vvi(n);
  for (int i = 1; i < n; i++) {
    cin >> x;
    x--;
    g[x].push_back(i);
  }
  for (int i = 0; i < n; i++)
    if (!c[i])
      dfs(i);
  for (int i = 0; i < n; i++)
    cout << c[i] - 1 << " \n"[i == n-1];
}
