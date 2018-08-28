// https://cses.fi/problemset/task/1132
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi dp1, dp2, p1, p2, m;
vvi g;

void dfs(int u, int p) {
  int a = 0, b = 0, c, d;
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    if (dp1[z] >= b) {
      b = dp1[z] + 1;
      d = z;
      if (b > a) {
        swap(a, b);
        swap(c, d);
      }
    }
  }
  dp1[u] = a;
  dp2[u] = b;
  p1[u] = c;
  p2[u] = d;
}

void dfs2(int u, int p) {
  for (auto z:g[u]) {
    if (z == p) continue;
    if (z == p1[u]) m[z] = max(m[u] + 1, 1 + dp2[u]);
    else m[z] = max(m[u] + 1, 1 + dp1[u]);
    dfs2(z, u);
  }
}

int main() {
  int n, a, b;
  cin >> n;
  dp1 = vi(n);
  dp2 = vi(n);
  p1 = vi(n);
  p2 = vi(n);
  m = vi(n);
  g = vvi(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  dfs2(0, -1);
  for (int i = 0; i < n; i++) {
    cout << max(m[i], dp1[i]);
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}
