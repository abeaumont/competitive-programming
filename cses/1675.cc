// https://cses.fi/problemset/task/1675
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using viii = vector<iii>;

vi s, p;

int find(int i) {
  if (i == p[i])
    return i;
  return p[i] = find(p[i]);
}

bool unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j)
    return 0;
  if (s[i] < s[j])
    swap(i, j);
  s[i] += s[j];
  p[j] = i;
  return 1;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v, w;
  cin >> n >> m;
  viii e(m);
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    u--, v--;
    e[i] = {w, u, v};
  }
  sort(e.begin(), e.end());
  s = vi(n, 1);
  p = vi(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  ll c = 0;
  for (iii x : e) {
    tie(w, u, v) = x;
    if (unite(u, v)) {
      c += w;
      n--;
    }
  }
  if (n == 1)
    cout << c << '\n';
  else
    cout << "IMPOSSIBLE\n";
}
