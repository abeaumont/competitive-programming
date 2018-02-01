// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/min-difference-queries-f5b9c199/
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef set<int> si;
typedef unordered_map<int, int> mii;
typedef unordered_set<int> usi;
typedef vector<int> vi;
typedef vector<vi> vvi;

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
  int c = ceil(sqrt(n));
  vvi s(c);
  for (int i = 0; i < n; i += c) {
    usi d;
    for (int j = i; j < n; j++) {
      if (d.count(a[j])) continue;
      s[i / c].push_back(a[j]);
      d.insert(a[j]);
      if (s[i / c].size() > c) break;
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
    int x = l / c;
    si d;
    bool found = false;
    for (auto y : s[x]) {
      int idx1 = lower_bound(b[y].begin(), b[y].end(), l) - b[y].begin();
      int idx2 = upper_bound(b[y].begin(), b[y].end(), r) - b[y].begin();
      int z = idx2 - idx1;
      if (!z) continue;
      if (d.count(z)) {
        found = true;
        break;
      }
      d.insert(z);
    }
    if (found) {
      last = 0;
    } else if (d.size() <= 1) {
      last = -1;
    } else {
      int M = r - l + 2;
      int x = -1;
      for (auto y : d) {
        if (x != -1) M = min(M, y - x);
        x = y;
      }
      last = M;
    }
    cout << last << endl;
  }
}
