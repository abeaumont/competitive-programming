// https://www.codechef.com/OCT19A/problems/MARM
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  ll t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      ll d = k / n;
      if (k % n > i) d++;
      if (i == n - i - 1) {
        if (d) cout << 0;
        else cout << a[i];
      } else if (i < n / 2) {
        if (d % 3 == 0) cout << a[i];
        else if (d % 3 == 1) cout << (a[i] ^ a[n - i - 1]);
        else cout << a[n - i - 1];
      } else {
        if (d % 3 == 0) cout << a[i];
        else if (d % 3 == 1) cout << a[n - i - 1];
        else cout << (a[i] ^ a[n - i - 1]);
      }
      cout << " \n"[i == n - 1];
    }
  }
}
