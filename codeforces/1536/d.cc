// https://codeforces.com/contest/1536/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> s;
    auto it = s.begin();
    bool ok = 1;
    while (n--) {
      cin >> x;
      s.insert(x);
      auto it2 = s.find(x);
      if (it == it2 || prev(it2) == it || next(it2) == it) it = it2;
      else
        ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
