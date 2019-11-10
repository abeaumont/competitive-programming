// https://open.kattis.com/problems/stogovi
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using viii = vector<iii>;

int n;
vi p, m;
vvi anc;

void ancestors() {
  anc.push_back(vi(n));
  for (int i = 0; i < n; i++) anc[0][i] = p[m[i]];
  for (int i = 1, j = 1; i < n; i *= 2, j++) {
    anc.push_back(vi(n));
    for (int k = 0; k < n; k++) anc[j][k] = anc[j-1][anc[j-1][k]];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int v, w;
  char t;
  cin >> n;
  n++;
  vi d(n), x(n);
  m = vi(n);
  p = vi(n);
  vii r;
  viii q;
  for (int i = 1; i < n; i++) {
    cin >> t >> v;
    v = m[v];
    if (t == 'a') {
      m[i] = i;
      x[i] = i;
      p[i] = v;
      d[i] = d[p[i]] + 1;
    } else if (t == 'b') {
      m[i] = p[v];
      r.push_back({i, x[v]});
    } else {
      cin >> w;
      w = m[w];
      m[i] = v;
      q.push_back({i, m[i], w});
    }
  }
  ancestors();
  for (iii z : q) {
    int l;
    tie(l, v, w) = z;
    v = m[v], w = m[w];
    while (d[w] > d[v]) {
      int b = d[w] - d[v];
      int k = 1, j = 0;
      while (k * 2 < b) {
        j++;
        k *= 2;
      }
      w = anc[j][w];
    }
    while (d[v] > d[w]) {
      int b = d[v] - d[w];
      int k = 1, j = 0;
      while (k * 2 < b) {
        j++;
        k *= 2;
      }
      v = anc[j][v];
    }
    while (w != v) {
      int j = 0;
      while (anc[j + 1][w] != anc[j + 1][v]) j++;
      w = anc[j][w];
      v = anc[j][v];
    }
    r.push_back({l, d[w]});
  }
  sort(r.begin(), r.end());
  for (ii z : r) cout << get<1>(z) << "\n";
}
