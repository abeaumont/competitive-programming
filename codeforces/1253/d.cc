// https://codeforces.com/contest/1253/problem/D
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi p, s, mi, mx;

int find(int i) {
  if(i == p[i]) return i;
  return p[i] = find(p[i]);
};

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (s[i] < s[j]) swap(i,j);
  mi[i] = min(mi[i], mi[j]);
  mx[i] = max(mx[i], mx[j]);
  s[i] += s[j];
  p[j] = i;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n >> m;
  s = vi(n, 1), p = vi(n), mi = vi(n), mx = vi(n);
  for(int i = 0; i < n; i++) p[i] = i, mi[i] = i, mx[i] = i;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    unite(u, v);
  }
  int c = 0;
  for(int i = 0; i < n; i++) {
    int x = find(i);
    if (i != mi[x]) continue;
    int y = mx[x];
    for (int j = i + 1; j < y; j++) {
      int z = find(j);
      if (z != x) {
        unite(x, z);
        x = find(x);
        y = mx[x];
        c++;
      }
    }
  }
  cout << c << '\n';
}
