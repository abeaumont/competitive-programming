// https://open.kattis.com/problems/nsum
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, sum = 0;
  cin >> n;
  while (n--) cin >> x, sum += x;
  cout << sum << '\n';
}
