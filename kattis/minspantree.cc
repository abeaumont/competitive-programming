// https://open.kattis.com/problems/minspantree
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;

vi p, s;

int find(int a) {
  if (a == p[a])
    return a;
  return p[a] = find(p[a]);
}

bool unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b)
    return 0;
  if (s[a] < s[b])
    swap(a, b);
  p[b] = a;
  s[a] += s[b];
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, m, u, v, w, W = 0;
    cin >> n >> m;
    if (!n)
      break;
    p = vi(n);
    for (int i = 0; i < n; i++)
      p[i] = i;
    s = vi(n, 1);
    viii e(m);
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      if (u > v)
        swap(u, v);
      e[i] = {w, u, v};
    }
    sort(e.begin(), e.end());
    vii r;
    for (iii x : e) {
      tie(w, u, v) = x;
      if (unite(u, v)) {
        r.push_back({u, v});
        W += w;
      }
    }
    if (r.size() != n - 1) {
      cout << "Impossible\n";
      continue;
    }
    sort(r.begin(), r.end());
    cout << W << '\n';
    for (int i = 0; i < n - 1; i++) {
      tie(u, v) = r[i];
      cout << u << ' ' << v << '\n';
    }
  }
}
