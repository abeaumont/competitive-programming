// https://cses.fi/problemset/task/1071/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t, y, x;
  cin >> t;
  while (t--) {
    cin >> y >> x;
    int a = max(y, x);
    int b = min(y, x);
    ll s = ll(a - 1) * (a - 1);
    if (a == b) s += a;
    else if (a % 2) {
      if (x == a) s+= a * 2 - y;
      else s += x;
    } else {
      if (y == a) s += a * 2 - x;
      else s += y;
    }
    cout << s << endl;
  }
}
