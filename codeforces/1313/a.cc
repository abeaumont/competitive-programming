// https://codeforces.com/contest/1313/problem/A
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int best, a, b, c;
vvi all = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
vvi sets;

void subsets(int i) {
  if (i == 7) {
    int x = a, y = b, z = c;
    int s = 0;
    for (auto p : sets) {
      if (p[0] > x || p[1] > y || p[2] > z) return;
      s++, x -= p[0], y -= p[1], z -= p[2];
    }
    if (s > best) best = s;
    return;
  }
  sets.push_back(all[i]);
  subsets(i+1);
  sets.pop_back();
  subsets(i+1);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int k;
  cin >> k;
  while (k--) {
    cin >> a >> b >> c;
    sets = vvi();
    best = 0;
    subsets(0);
    cout << best << '\n';
  }
}
