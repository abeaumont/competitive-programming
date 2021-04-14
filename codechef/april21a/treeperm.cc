// https://www.codechef.com/APRIL21A/problems/TREEPERM
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using si = unordered_multiset<int>;
using vvi = vector<vi>;

const ll M = 1e9 + 7;

int n;
vvi g;
vi a, b, e, f;
si c, d;

bool dfs(int u, int p) {
  bool used = 0;
  ll cs = 0, es = 0, prod = 1;
  si tc, td;
  for (int v : g[u])
    if (v != p) {
      bool ok = dfs(v, u);
      if (!ok) return 0;
      if (e[v] && es) return 0;
      if (e[v]) es = v, swap(c, tc), swap(d, td);
      (prod *= f[v]) %= M;
      cs++;
    }
  if (es) f[u] = prod;
  else if (cs)
    f[u] = (prod * (cs + 1)) % M;
  else
    f[u] = 1;
  swap(c, tc), swap(d, td);
  if (a[u] != b[u]) {
    if (d.count(a[u])) d.erase(d.find(a[u]));
    else
      c.insert(a[u]);
    if (c.count(b[u])) c.erase(c.find(b[u]));
    else
      d.insert(b[u]);
  }
  if (!c.empty() || !d.empty()) e[u] = 1;
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, s, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    g = vvi(n), a = vi(n), b = vi(n), e = vi(n), f = vi(n);
    c.clear(), d.clear();
    for (int i = 0; i < n - 1; i++)
      cin >> u >> v, u--, v--, g[u].push_back(v), g[v].push_back(u);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    bool ok = dfs(0, -1);
    if (e[0]) ok = 0;
    if (!ok) cout << "0\n";
    else if (s == 2)
      cout << f[0] << "\n";
    else
      cout << "1\n";
  }
}
