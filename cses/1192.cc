// https://cses.fi/problemset/task/1192/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> si;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int find(vi &l, int x) {
  while (x != l[x]) x = l[x];
  return x;
}

void unite(vi &l, vi &s, int a, int b) {
  a = find(l, a);
  b = find(l, b);
  if (a == b) return;
  if (s[a] < s[b]) swap(a, b);
  s[a] += s[b];
  l[b] = a;
}

int main() {
  int n, m;
  cin >> n >> m;
  vi l(n * m, -1), s(n * m, 1);
  vvb a(n);
  for (int i = 0; i < n; i++) {
    a[i] = vb(m, false);
    for (int j = 0; j < m; j++) {
      char b;
      cin >> b;
      if (b == '.') {
        a[i][j] = true;
        l[i * m + j] = i * m + j;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j < m - 1 && a[i][j] && a[i][j + 1])
        unite(l, s, i * m + j, i * m + j + 1);
      if (i < n - 1 && a[i][j] && a[i + 1][j])
        unite(l, s, i * m + j, (i + 1) * m + j);
    }
  }
  si r;
  for (auto x : l) if (x >= 0) r.insert(find(l, x));
  cout << r.size() << endl;
}
