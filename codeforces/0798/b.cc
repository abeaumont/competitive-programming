// https://codeforces.com/contest/798/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using msvi = unordered_map<string, vi>;

int main() {
  int n;
  cin >> n;
  msvi m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      string t = s.substr(j) + s.substr(0, j);
      if (!m.count(t)) m[t] = vi(n, 51);
      if (j < m[t][i]) m[t][i] = j;
    }
  }
  int M = n * 51;
  for (auto x : m) {
    bool ok = 1;
    int s = 0;
    for (int y : x.second)
      if (y == 51) {
        ok = 0;
        break;
      } else s += y;
    if (ok) M = min(M, s);
  }
  if (M < n * 51) cout << M << '\n';
  else cout << "-1\n";
}
