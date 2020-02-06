// https://www.codechef.com/DEC19A/problems/CHFRAN
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;
using qii = priority_queue<ii, vii, greater<ii>>;

int main() {
  int t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    vii a(n);
    int m = 2e9, M = 0;
    qii q;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      if (l > M) M = l;
      if (r < m) m = r;
      q.push({l, -1});
      q.push({r, 1});
    }
    if (m >= M) {
      cout << "-1\n";
      continue;
    }
    sort(a.begin(), a.end());
    int c = 0;
    m = 2e9;
    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.top();
      q.pop();
      if (x >= M) break;
      y = -y;
      c += y;
      if (y < 0 && c < m) m = c;
    }
    cout << m << '\n';
  }
}
