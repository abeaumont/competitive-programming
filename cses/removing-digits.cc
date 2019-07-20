// https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c = 0;
  cin >> n;
  while (n) {
    int x = n, m = 0;
    while (x) {
      m = max(m, x % 10);
      x /= 10;
    }
    n -= m;
    c++;
  }
  cout << c << endl;
}
