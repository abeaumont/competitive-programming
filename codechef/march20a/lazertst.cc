// https://www.codechef.com/MARCH20A/problems/LAZERTST
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int t, n, m, k, q, l, r, h;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k >> q;
    vi ls(q), rs(q);
    for (int i = 0; i < q; i++)
      cin >> ls[i] >> rs[i];
    vi r(q);
    for (int i = 0; i < q; i++) {
      if (k < q) { r[i] = m-1; continue; }
      cout << 1 << ' ' << ls[i] << ' ' << rs[i] << ' ' << m/2 << '\n';
      cout.flush();
      cin >> r[i];
      assert(r[i] >= 0);
    }
    cout << 2;
    for (int i = 0; i < q; i++)
      cout << ' ' << r[i];
    cout << '\n';
    cout.flush();
    cin >> h;
    assert(h==1);
  }
}
