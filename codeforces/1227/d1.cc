// https://codeforces.com/contest/1227/problem/D1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, k, p;
  cin >> n;
  vi c(n);
  vii a(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    c[i] = x;
    a[i] = { x, -i };
  }
  sort(a.begin(), a.end(), greater<ii>());
  cin >> m;
  viii b(m);
  for (int i = 0; i < m; i++) {
    cin >> k >> p;
    b[i] = { k, p, i };
  }
  vi r(m);
  indexed_set s;
  sort(b.begin(), b.end());
  int j = 0;
  for (iii x : b) {
    int i;
    tie(k, p, i) = x;
    while (s.size() < k)
      s.insert(-get<1>(a[j++]));
    r[i] = c[*s.find_by_order(p - 1)];
  }
  for (int x : r) cout << x << '\n';
}
