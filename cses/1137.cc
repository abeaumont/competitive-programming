// https://cses.fi/problemset/task/1137/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const int N = 200100;
ll n, q, t, k, x, b[N], s[N], c[N], tree[N];
bool v[N];
vi a(1);
vvi g;

ll sum(int k) {
  ll s = 0;
  for (; k >= 1; k -= k & -k) s += tree[k];
  return s;
}

ll sum(int a, int b) {  return sum(b) - sum(a - 1); }

void add(int k, ll x) {
  for (; k <= n; k += k & -k) tree[k] += x;
}

void dfs(int i) {
  if (v[i]) return;
  v[i] = true;
  a.push_back(i);
  ll c = 1;
  for (auto z:g[i]) {
    dfs(z);
    c += s[z];
  }
  s[i] = c;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> c[i];
  g = vvi(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) b[a[i]] = i;
  for (int i = 1; i <= n; i++) add(i, c[a[i]]);
  while (q--) {
    cin >> t >> k;
    if (t == 1) {
      cin >> x;
      add(b[k], x - c[k]);
      c[k] = x;
    } else cout << sum(b[k], b[k] + s[k] - 1) << endl;
  }
}
