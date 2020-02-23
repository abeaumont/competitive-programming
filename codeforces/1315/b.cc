// https://codeforces.com/contest/1315/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, a, b, p;
  cin >> t;
  while (t--) {
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    int k = n, c = s[n-2];
    if (c == 'A') p -= a;
    else p -= b;
    if (p < 0) {
      cout << k << '\n';
      continue;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == c) {
        k = i+1;
        continue;
      }
      c = s[i];
      if (s[i] == 'A') p -= a;
      else p -= b;
      if (p < 0) break;
      k = i+1;
    }
    cout << k << '\n';
  }
}
