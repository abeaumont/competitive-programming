// https://cses.fi/problemset/task/1091/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m;
  multiset<int, greater<int>> h;
  while (n--) {
    cin >> x;
    h.insert(x);
  }
  while (m--) {
    cin >> x;
    auto it = h.lower_bound(x);
    if (it == h.end()) cout << "-1\n";
    else {
      cout << *it << endl;
      h.erase(it);
    }
  }
}
