// https://atcoder.jp/contests/abc199/tasks/abc199_c
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio();
  int n, q, t, a, b, p = 0;
  string s;
  cin >> n >> s >> q;
  while (q--) {
    cin >> t >> a >> b, a--, b--;
    if (t == 2) p = (p + 1) % 2;
    else {
      if (p) {
        a = (a + n) % (2 * n);
        b = (b + n) % (2 * n);
      }
      swap(s[a], s[b]);
    }
  }
  for (int i = n * p; i < n * (p + 1); i++) cout << s[i];
  p = (p + 1) % 2;
  for (int i = n * p; i < n * (p + 1); i++) cout << s[i];
  cout << '\n';
}
