// https://open.kattis.com/problems/perfectpowers
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    ll x, m = 1;
    cin >> x;
    if (!x)
      break;
    if (x < 0) {
      for (ll i = 2; i * i <= -x; i++)
        for (ll j = -i, k = 1; labs(j) <= -x; j *= -i, k++)
          if (j == x && k > m)
            m = k;
    } else
      for (ll i = 2; i * i <= labs(x); i++)
        for (ll j = i, k = 1; j <= x; j *= i, k++)
          if (j == x && k > m)
            m = k;
    cout << m << '\n';
  }
}
