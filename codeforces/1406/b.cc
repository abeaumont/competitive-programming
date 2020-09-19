// https://codeforces.com/contest/1406/problem/B
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll r = a[0] * a[1] * a[2] * a[3] * a[4];
    r = max(r, a[0] * a[1] * a[2] * a[3] * a[n - 1]);
    r = max(r, a[0] * a[1] * a[2] * a[n - 2] * a[n - 1]);
    r = max(r, a[0] * a[1] * a[n - 3] * a[n - 2] * a[n - 1]);
    r = max(r, a[0] * a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1]);
    r = max(r, a[n - 5] * a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1]);
    cout << r << '\n';
  }
}
