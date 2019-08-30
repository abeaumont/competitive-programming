// https://cses.fi/problemset/task/1130
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, a, b;
vi dp1, dp2;
vvi g;

void dfs(int u, int p) {
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    dp2[u] += max(dp1[z], dp2[z]);
  }
  for (auto z:g[u]) {
    if (z == p) continue;
    dp1[u] = max(dp1[u], 1 + dp2[u] + dp2[z] - max(dp1[z], dp2[z]));
  }
}

int main() {
  cin >> n;
  dp1 = vi(n);
  dp2 = vi(n);
  g = vvi(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  cout << max(dp1[0], dp2[0]) << endl;
}
