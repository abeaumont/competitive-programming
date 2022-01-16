// https://codeforces.com/contest/1627/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ll k = (n + 1) / 2 + (m + 1) / 2 - 1;
    string sep = "";
    int c = 0;
    for (ll i = 0; i < k; i++) {
      ll j = min(i, k - (i + 1)) + 1;
      ll r = min(j, min((m + 1) / 2, (n + 1) / 2)) * 4;
      if (!i) {
        if (n % 2 && m % 2) r = 1;
        else if (n % 2 || m % 2)
          r = 2;
      } else {
        if (i < (m + 1) / 2 && n % 2) r -= 2;
        if (i < (n + 1) / 2 && m % 2) r -= 2;
      }
      c += r;
      for (int l = 0; l < r; l++) {
        cout << sep << n / 2 + m / 2 + i;
        sep = " ";
      }
    }
    assert(c == n * m);
    cout << '\n';
  }
}
