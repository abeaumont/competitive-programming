// https://cses.fi/problemset/task/2168/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using indexed_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag,
                              tree_order_statistics_node_update>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x, y, k;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> x >> y, a[i] = {x, y, i};
  vector<int> ans(n);
  indexed_multiset m;
  sort(a.begin(), a.end(), [](auto i, auto j) {
    return get<1>(i) < get<1>(j) ||
           (get<1>(i) == get<1>(j) && get<0>(i) > get<0>(j));
  });
  for (int i = 0; i < n; i++) {
    tie(x, y, k) = a[i];
    ans[k] = m.size() - m.order_of_key(x);
    m.insert(x);
  }
  for (int i = 0; i < n; i++) cout << (ans[i] ? 1 : 0) << " \n"[i == n - 1];
  m.clear();
  sort(a.begin(), a.end(), [](auto i, auto j) {
    return get<0>(i) < get<0>(j) ||
           (get<0>(i) == get<0>(j) && get<1>(i) > get<1>(j));
  });
  for (int i = 0; i < n; i++) {
    tie(x, y, k) = a[i];
    ans[k] = m.size() - m.order_of_key(y);
    m.insert(y);
  }
  for (int i = 0; i < n; i++) cout << (ans[i] ? 1 : 0) << " \n"[i == n - 1];
}
