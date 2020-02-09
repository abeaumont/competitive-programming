// https://codeforces.com/contest/1300/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << (a[n] - a[n-1]) << '\n';
  }
}
