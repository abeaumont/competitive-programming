// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, l, r;
  cin >> n >> q;
  vector<long long> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    cout << a[r] - a[l - 1] << "\n";
  }
}
