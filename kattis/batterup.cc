// https://open.kattis.com/problems/batterup
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c = 0, s = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0) c++, s += x;
  }
  cout << double(s) / c << '\n';
}
