// https://open.kattis.com/problems/ceremony
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int ans = n;
  for (int i = 0; i < n; i++) ans = min(ans, i + a[i]);
  cout << ans << '\n';
}
