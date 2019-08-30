// https://cses.fi/problemset/task/1133
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<ll> vi;
typedef vector<vi> vvi;

vvi g;
vvi m1, m2;
vi c, d, e, f;

void dfs(int u, int p) {
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    ll a = 1 + c[z];
    ll b = a + d[z];
    m1[u].push_back(a);
    m2[u].push_back(b);
    c[u] += a;
    d[u] += b;
  }
}

void dfs2(int u, int i, int p) {
  if (p != -1) {
    ll a = e[p] + c[p] - m1[p][i];
    ll b = f[p] + d[p] - m2[p][i];
    e[u] = 1 + a;
    f[u] = 1 + a + b;
  }
  for (int i = 0, j = 0; i < g[u].size(); i++) {
    int z = g[u][i];
    if (z == p) continue;
    dfs2(z, j, u);
    j++;
   }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  g = vvi(n); m1 = vvi(n); m2 = vvi(n);
  c = vi(n); d = vi(n); e = vi(n), f = vi(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  dfs2(0, 0, -1);
  for (int i = 0; i < n; i++) {
    cout << d[i] + f[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}
