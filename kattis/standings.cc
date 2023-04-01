// https://open.kattis.com/problems/standings
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    vector<ll> x(n);
    for (int i = 0; i < n; i++) cin >> s >> x[i];
    sort(x.begin(), x.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll d = x[i] - (i + 1);
      ans += d < 0 ? -d : d;
    }
    cout << ans << '\n';
  }
}
