// https://www.codechef.com/DEC19A/problems/STICNOT
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, u, v, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vi a(n), b(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> u >> v >> x, b[i] = x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int c = 0, k = 0;
    if (a[0] >= b[0]) k++;
    else c++;
    for (int i = 0; i < n - 1; i++)
      if (a[k] >= b[i]) k++;
      else c++;
    cout << c << '\n';
  }
}
