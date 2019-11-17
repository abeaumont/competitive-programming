// https://codeforces.com/contest/1169/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, x, b, y, p, q;
  cin >> n >> a >> x >> b >> y;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    p = a + i;
    if (p > n) p -= n;
    q = b - i;
    if (q < 1) q += n;
    if (p == q) ok = true;
    if (p == x) break;
    if (q == y) break;
  }
  cout << (ok ? "YES\n" : "NO\n");
}
