// https://codeforces.com/contest/1304/problem/E
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

typedef vector<ll> vi;
typedef vector<vi> vvi;

ll INF = 2e9;
ll n, q, u, v;
vi a, d;
vvi g, anc;

void dfs(ll u, ll p) {
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
  for (ll i = 0; i < n; i++) anc[0][i] = a[i];
  for (ll i = 1, j = 1; i < n; i *= 2, j++) {
    anc.push_back(vi(n));
    for (ll k = 0; k < n; k++) anc[j][k] = anc[j-1][anc[j-1][k]];
  }
}

ll dist(ll u, ll v) {
    ll c = d[u] + d[v];
     while (d[u] > d[v]) {
      ll b = d[u] - d[v];
      ll k = 1, j = 0;
      while (k*2 < b) {
        j++;
        k *= 2;
      }
      u = anc[j][u];
    }
    while (d[v] > d[u]) {
      ll b = d[v] - d[u];
      ll k = 1, j = 0;
      while (k*2 < b) {
        j++;
        k *= 2;
      }
      v = anc[j][v];
    }
    while (u != v) {
      ll j = 0;
      while (anc[j+1][u] != anc[j+1][v]) j++;
      u = anc[j][u];
      v = anc[j][v];
    }
    return c - 2 * d[u];;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  g = vvi(n);
  a = vi(n); d = vi(n);
  for (ll i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  ancestors();
  cin >> q;
  while (q--) {
    ll x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    x--, y--, a--, b--;
    ll dab = dist(a, b);
    ll dax = dist(a, x);
    ll day = dist(a, y);
    ll dbx = dist(b, x);
    ll dby = dist(b, y);
    ll even = INF;
    ll odd = INF;
    for (ll x : {dab, dax+1+dby, day+1+dbx})
      if (x % 2 == 0) even = min(even, x);
      else odd = min(odd, x);
    if (k % 2 == 0) cout << (k >= even ? "YES\n":"NO\n");
    else cout << (k >= odd ? "YES\n":"NO\n");
  }
}
