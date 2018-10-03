// https://cses.fi/problemset/task/1098/
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s ^= x%4;
    }
    cout << (s ? "first\n" : "second\n");
  }
}
