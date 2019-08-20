// https://cses.fi/problemset/task/1632
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using ibi = tuple<int, bool, int>;
using vii = vector<ii>;
using vibi = vector<ibi>;
using si = set<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, x, y, l = 0, r = 0;
  cin >> n >> k;
  vii a(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[i] = {y, x};
  }
  sort(a.begin(), a.end(), greater<ii>());
  vibi b(2*n);
  for (int i = 0; i < n; i++) {
    tie(y, x) = a[i];
    b[2*i] = {x, 0, i};
    b[2*i + 1] = {y, 1, i};
  }
  sort(b.begin(), b.end());
  si c;
  for (int i = 0; i < 2 * n; i++) {
    bool z;
    tie(y, z, x) = b[i];
    if (!z) c.insert(x), l++;
    else if (c.count(x)) c.erase(x), l--, r++;
    if (i < 2 * n - 1 && get<0>(b[i + 1]) == y) continue;
    if (l > k) c.erase(c.begin()), l--;
  }
  cout << r << "\n";
}
