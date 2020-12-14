// https://www.codechef.com/DEC20A/problems/EVENPSUM
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    ll ans = ((a + 1) / 2) * ((b + 1) / 2);
    ans += (a / 2) * (b / 2);
    cout << ans << '\n';
  }
}
