// https://open.kattis.com/problems/zanzibar
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long s = 0;
    int p;
    cin >> p;
    while (true) {
      int x;
      cin >> x;
      if (!x) break;
      int d = x - 2 * p;
      if (d > 0) s += d;
      p = x;
    }
    cout << s << endl;
  }
}
