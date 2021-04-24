// https://codeforces.com/contest/1517/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 2050000000000000000LL;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2050) {
      cout << "-1\n";
      continue;
    }
    ll s = 0;
    for (ll i = M; i >= 2050; i /= 10) {
      ll k = n / i;
      s += k;
      n -= k * i;
    }
    assert(!n);
    cout << s << '\n';
  }
}
