// https://cses.fi/problemset/task/1138
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int n, q, k;
vvi g;
vi c, s, s2, v, id, m, t;

ll sum(int k) {
  ll s = 0;
  while (k >= 1) {
    s += t[k];
    k -= k&-k;
  }
  return s;
}

ll sum(int a, int b) { return sum(b) - sum(a - 1); }

void add(int i, ll x) { for (; i <= n; i += i&-i) t[i] += x; }

void dfs(int u, int p) {
  id.push_back(u);
  s[u] = s[p] + v[u];
  c[u] = 1;
  for (auto z:g[u]) {
    if (z == p) continue;
    dfs(z, u);
    c[u] += c[z];
  }
}

int main() {
  cin >> n >> q;
  g = vvi(n + 1);
  v = vi(n + 1); s = vi(n + 1); s2 = vi(n + 1); c = vi(n + 1); id = vi(1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (k = 1; k < n; k *= 2);
  t = vi(k + 1);
  dfs(1, 0);
  m = vi(n + 1);
  for (int i = 1; i <= n; i++) m[id[i]] = i;
  s2[1] = s[id[1]];
  for (int i = 2; i <= n; i++) s2[i] = s[id[i]] - s[id[i - 1]];
  for (int i = 1; i <= n; i++) add(i, s2[i]);
  while (q--) {
    int x, y, z;
    cin >> x >> y;
    if (x == 1) {
      cin >> z;
      int dd = z - v[y];
      add(m[y], dd);
      add(m[y] + c[y], -dd);
      v[y] = z;
    } else cout << sum(m[y]) << endl;
  }
}
