// https://codeforces.com/contest/1241/problem/B
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    vi a(26);
    for (char c : s) a[c - 'a'] = 1;
    bool ok = 0;
    for (char c : t)
      if (a[c - 'a'])
        ok = 1;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
}
