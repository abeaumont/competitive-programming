// https://codeforces.com/problemset/problem/1307/D
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = tuple<ll, ll>;
using vi =vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using qi = queue<int>;

int n;
vi x;
vvi y;

void f() {
  y.push_back(vi(n));
  for (int i=0; i < n; i++) y[0][i] = x[i];
  for (int i=1, k=2; k <= n; i++, k *= 2) {
    y.push_back(vi(n - k + 1));
    for (int j = 0; j <= n - k; j++)
      y[i][j] = max(y[i-1][j], y[i-1][j + k/2]);
  }
}

int mx(int a, int b) {
  if (a>b) return -1;
  int d=b-a+1;
  int i=0, k=1;
  for (; k*2 <= d; i++, k *= 2);
  return max(y[i][a], y[i][b-k+1]);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll m, k, u, v;
  cin >> n >> m >> k;
  vi c(k);
  for (int i = 0; i < k; i++)
    cin >> u, u--, c[i] = u;
  vvi g(n);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi a(n), s(n);
  a[0]=0, s[0]=1;
  qi q;
  q.push(0);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (s[v]) continue;
      s[v] = 1;
      a[v] = a[u]+1;
      q.push(v);
    }
  }
  vi b(n);
  s=vi(n);
  b[n-1] = 0, s[n-1] = 1;
  q.push(n-1);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (s[v]) continue;
      s[v] = 1;
      b[v] = b[u]+1;
      q.push(v);
    }
  }
  x = vi(n, -1);
  for (int i=0; i<k; i++)
    x[a[c[i]]] = max(x[a[c[i]]], b[c[i]]);
  f();
  vi d(k);
  for (int i = 0; i < k; i++)
    d[i] = a[c[i]];
  sort(d.begin(), d.end());
  for (int i = 0; i < k-1; i++)
    if (d[i] == d[i+1]) {
      cout << a[n-1] << '\n';
      return 0;
    }
  ll M = 0;
  for (int i = 0; i < k; i++) {
    ll x = mx(d[i]+1,n-1);
    if (x >= 0) M = max(M, d[i]+x+1);
  }
  cout << min(M, a[n-1]) << '\n';
}
