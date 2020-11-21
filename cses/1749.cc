// https://cses.fi/problemset/task/1749
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, x;
  cin >> n;
  vector<int> a(n);
  tree<int, null_type, less<int>, rb_tree_tag,
       tree_order_statistics_node_update>
      s;
  for (int i = 0; i < n; i++) cin >> a[i], s.insert(i);
  for (int i = 0; i < n; i++) {
    cin >> x;
    auto k = s.find_by_order(x - 1);
    cout << a[*k] << " \n"[i == n - 1];
    s.erase(k);
  }
}
