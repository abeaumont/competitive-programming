// https://cses.fi/problemset/task/1650
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, l, r;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
  while (q--) cin >> l >> r, cout << (a[r] ^ a[l - 1]) << "\n";
}
