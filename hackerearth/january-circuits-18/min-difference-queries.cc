// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/min-difference-queries-f5b9c199/
#include <cmath>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int, int> mii;
typedef vector<mii> vmii;

int above(const vvi& b, int i, int k) {
  int x = 0, y = b[i].size() - 1;
  while (x <= y) {
    int m = (x + y) / 2;
    if (b[i][m] == k) return m;
    if (b[i][m] < k) x = m + 1;
    else y = m - 1;
  }
  return x;
}

int below(const vvi& b, int i, int k) {
  int x = 0, y = b[i].size() - 1;
  while (x <= y) {
    int m = (x + y) / 2;
    if (b[i][m] == k) return m;
    if (b[i][m] < k) x = m + 1;
    else y = m - 1;
  }
  return y;
}

int main() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  mii m;
  int k = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (m.count(x)) a[i] = m[x];
    else m[x] = a[i] = k++;
  }
  vvi b(k);
  for (int i = 0; i < n; i++) b[a[i]].push_back(i);
  int c = sqrt(n);
  vmii s(c + 1);
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j < k; j++) {
      int idx1 = above(b, j, i * c);
      if (idx1 >= b[j].size() || b[j][idx1] >= (i + 1) * c) continue;
      int idx2 = below(b, j, (i + 1) * c - 1);
      s[i][j] = idx2 - idx1 + 1;
    }
  }
  int last = 0;
  for (int i = 0; i < q; i++) {
    int u, v, l, r;
    cin >> u >> v;
    l = (u + last) % n;
    if (l < 0) l += n;
    r = (v + last) % n;
    if (r < 0) r += n;
    mii f;
    int x = l / c;
    int y = r / c;
    if (x == y) for (int j = l; j <= r; j++) f[a[j]]++;
    else {
      if (l % c) for (int j = l; j < (x + 1) * c; j++) f[a[j]]++;
      else for (auto z : s[x]) f[z.first] += z.second;
      for (int j = x + 1; j < y; j++) for (auto z : s[j]) f[z.first] += z.second;
      if (r % c == c - 1) for (auto z : s[y]) f[z.first] += z.second;
      else for (int j = y * c; j <= r; j++) f[a[j]]++;
    }
    if (f.size() == 1) {
      last = -1;
    } else {
      vi t(r - l + 1, 0);
      bool found = false;
      for (auto z : f) {
        if (t[z.second]) {
          found = true;
          break;
        }
        t[z.second]++;
      }
      if (found) {
        last = 0;
      } else {
        int M = r - l + 2;
        int j = 0;
        while (!t[j]) j++;
        for (int o = j + 1; o <= r - l; o++) {
          if (t[o]) {
            M = min(M, o - j);
            if (M == 1) break;
            j = o;
          }
        }
        last = M;
      }
    }
    cout << last << endl;
  }
}
