// https://codeforces.com/contest/1407/problem/A
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c += a[i];
    }
    if (c > n / 2) {
      c -= c % 2;
      cout << c << '\n';
      for (int i = 0; i < c; i++) cout << 1 << " \n"[i == c - 1];
    } else {
      c = n - c;
      cout << c << '\n';
      for (int i = 0; i < c; i++) cout << 0 << " \n"[i == c - 1];
    }
  }
}
