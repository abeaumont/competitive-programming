// https://cses.fi/problemset/task/1676
#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vi s, p;
int mx, cc;

int find(int i ) {
  if(i == p[i]) return i;
  return p[i] = find(p[i]);
}

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (s[i] < s[j]) swap(i, j);
  s[i] += s[j];
  if (s[i] > mx) mx = s[i];
  p[j] = i;
  cc--;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, u, v;
  cin >> n >> m;
  s = vi(n, 1);
  p = vi(n);
  cc = n;
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    unite(u, v);
    cout << cc << ' ' << mx << '\n';
  }
}
