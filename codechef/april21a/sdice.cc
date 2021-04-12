// https://www.codechef.com/APRIL21A/problems/SDICE
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    ll sum = n / 4 * 44;
    if (n % 4 == 0) sum += 16;
    else if (n % 4 == 1) {
      sum += 20;
      if (n > 4) sum += 12;
    } else if (n % 4 == 2) {
      sum += 36;
      if (n > 4) sum += 8;
    } else {
      sum += 51;
      if (n > 4) sum += 4;
    }
    cout << sum << '\n';
  }
}
