// https://cses.fi/problemset/task/1677
#include <bits/stdc++.h>

using namespace std;

using ii = tuple<int, int>;
using si = unordered_set<int>;
using vi = vector<int>;
using vii = vector<ii>;
using vsi = vector<si>;

vi s, p;
int mx, cc;

int find(int i) {
  if (i == p[i])
    return i;
  return p[i] = find(p[i]);
}

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j)
    return;
  if (s[i] < s[j])
    swap(i, j);
  s[i] += s[j];
  if (s[i] > mx)
    mx = s[i];
  p[j] = i;
  cc--;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, k, u, v;
  cin >> n >> m >> k;
  vsi g(n);
  s = vi(n, 1);
  p = vi(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  vii e(m);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    if (u > v)
      swap(u, v);
    e[i] = {u, v};
  }
  vii f(k);
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    u--, v--;
    if (u > v)
      swap(u, v);
    g[u].insert(v);
    f[i] = {u, v};
  }
  cc = n;
  for (ii x : e) {
    tie(u, v) = x;
    if (!g[u].count(v))
      unite(u, v);
  }
  vi r(k);
  for (int i = 0; i < k; i++) {
    r[k - i - 1] = cc;
    tie(u, v) = f[k - i - 1];
    unite(u, v);
  }
  for (int i = 0; i < k; i++)
    cout << r[i] << " \n"[i == k - 1];
}
