// https://cses.fi/problemset/task/1163/
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;
typedef set<ii> sii;

int main() {
  ios_base::sync_with_stdio(false);
  int x, n;
  cin >> x >> n;
  sii s{make_tuple(x, x)};
  sii t{make_tuple(x, x)};
  while (n--) {
    cin >> x;
    auto i = s.lower_bound(make_tuple(x, 0));
    int a, b;
    tie(a, b) = *i;
    s.erase(i);
    s.insert(make_tuple(x, b - (a - x)));
    s.insert(make_tuple(a, a - x));
    t.erase(make_tuple(b, a));
    t.insert(make_tuple(b - (a - x), x));
    t.insert(make_tuple(a - x, a));
    cout << get<0>(*t.rbegin());
    if (n > 0) cout << " ";
  }
  cout << endl;
}
