// https://www.aceptaelreto.com/problem/statement.php?id=326
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ii = tuple<int, int>;
using vii = vector<ii>;
using vvi = vector<vi>;

vi p, sz;

int find(int x) {
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}

void unite(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (sz[a] > sz[b]) swap(a, b);
  p[a] = b;
  sz[b] += sz[a];
  if (find(a) == find(b)) return;
}

int main() {
  int n, m, k, t, x, y;
  while (cin >> n >> m >> k >> t) {
    vvi g(n+1, vi(m+1, -1));
    g[0][0] = 0;
    g[n][m] = t+1;
    p = vi(t+2), sz = vi(t+2, 1);
    for (int i = 0; i < t+2; i++) p[i] = i;
    vii a(t);
    for (int i = 0; i < t; i++) {
      cin >> x >> y;
      a[i] = make_tuple(x, y);
    }
    bool found = 0;
    for (int i = t; i > 0; i--) {
      tie(x, y) = a[i - 1];
      g[x][y] = i;
      for (int j = max(0, x-10); j <= min(n, x+10); j++) {
        for (int l = max(0, y-10); l <= min(m, y+10); l++)
          if ((j-x) * (j-x) + (l-y) * (l-y) <= k*k && g[j][l] >= 0) {
            unite(i, g[j][l]);
            if (find(0) == find(t+1)) {
              found = 1;
              cout << x << ' ' << y << '\n';
              break;
            }
          }
        if (found) break;
      }
      if (found) break;
    }
    if (!found) cout << "NUNCA SE PUDO\n";
  }
}
