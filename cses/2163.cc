// https://cses.fi/problemset/task/2163/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using vi = vector<int>;

using namespace __gnu_pbds;
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int o = k;
  indexed_set s;
  for (int i = 1; i <= n; i++) s.insert(i);
  while (!s.empty()) {
    vector<int> d;
    for (int i = o % s.size(); i < s.size(); i += k + 1) {
      auto x = s.find_by_order(i);
      d.push_back(*x);
      cout << *x << " \n"[d.size() == s.size()];
      o = k + i + 1 - s.size();
    }
    for (int x : d) s.erase(x);
  }
}
