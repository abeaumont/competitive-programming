// https://cses.fi/problemset/task/1139
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> si;

vvi g;
vi c, d;
si s;

void dfs(int u, int p) {
  si t;
  t.insert(c[u]);
  for (int z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    if (s.size() > t.size()) swap(s, t);
    for (int x:s) t.insert(x);
  }
  d[u] = t.size();
  swap(s, t);
}

int main() {
  int n, u, v;
  cin >> n;
  g = vvi(n);
  c = vi(n); d = vi(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    cout << d[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}
