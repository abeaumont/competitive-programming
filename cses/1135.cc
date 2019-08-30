// https://cses.fi/problemset/task/1135
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, q, u, v;
vi a, d;
vvi g, anc;

void dfs(int u, int p) {
  if (p != -1) {
    a[u] = p;
    d[u] = d[p] + 1;
  }
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
  }
}

void ancestors() {
  anc.push_back(vi(n));
  for (int i = 0; i < n; i++) anc[0][i] = a[i];
  for (int i = 1, j = 1; i < n; i *= 2, j++) {
    anc.push_back(vi(n));
    for (int k = 0; k < n; k++) anc[j][k] = anc[j-1][anc[j-1][k]];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  g = vvi(n);
  a = vi(n); d = vi(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  ancestors();
  for (int i = 0; i < q; i++) {
    cin >> u >> v;
    u--; v--;
    int c = d[u] + d[v];
     while (d[u] > d[v]) {
      int b = d[u] - d[v];
      int k = 1, j = 0;
      while (k*2 < b) {
        j++;
        k *= 2;
      }
      u = anc[j][u];
    }
    while (d[v] > d[u]) {
      int b = d[v] - d[u];
      int k = 1, j = 0;
      while (k*2 < b) {
        j++;
        k *= 2;
      }
      v = anc[j][v];
    }
    while (u != v) {
      int j = 0;
      while (anc[j+1][u] != anc[j+1][v]) j++;
      u = anc[j][u];
      v = anc[j][v];
    }
    cout << c - 2 * d[u] << endl;
  }
}
