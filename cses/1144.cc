// https://cses.fi/problemset/task/1144/
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

char c;
int n, q, x, y, a[200001];
indexed_set s;

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  while (q--) {
    cin >> c >> x >> y;
    if (c == '?') cout << s.order_of_key(y + 1) - s.order_of_key(x)<< endl;
    else {
      x--;
      s.erase(s.find_by_order(s.order_of_key(a[x])));
      a[x] = y;
      s.insert(y);
    }
  }
}
