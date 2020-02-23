// https://codeforces.com/contest/1315/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using si = set<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    si s;
    for (int i = 1; i <= 2*n; i++) s.insert(i);
    vi a(2*n), b(n), c(n), d(n+1);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      c[i] = b[i];
      s.erase(b[i]);
    }
    sort(c.begin(), c.end());
    bool ok=1;
    for (int i = 0, j = 1; i < n; i++, j+=2) {
      if (c[i] > j) {
        ok=0;
        break;
      }
    }
    if (!ok) cout << "-1\n";
    else {
      for (int i = 0; i < n; i++) {
        a[2*i] = b[i];
        int next = *lower_bound(s.begin(), s.end(), b[i]);
        s.erase(next);
        a[2*i+1] = next;
      }
      for (int i = 0; i < 2*n; i++)
        cout << a[i] << " \n"[i==2*n-1];
    }
  }
}
