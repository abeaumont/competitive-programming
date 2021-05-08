// https://cses.fi/problemset/task/2428
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using indexed_set = tree<int, null_type, greater<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x, k;
  ll sum = 0;
  cin >> n >> k;
  map<int, int> m;
  indexed_set s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    auto it = m.find(x);
    if (it != m.end()) {
      s.erase(it->second + 1);
      m.erase(it);
    };
    m[x] = i;
    s.insert(i + 1);
    auto it1 = s.find_by_order(k);
    if (it1 == s.end()) sum += i + 1;
    else
      sum += i - *it1 + 1;
  }
  cout << sum << '\n';
}
