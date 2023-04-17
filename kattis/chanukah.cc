// https://open.kattis.com/problems/chanukah
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int p, k, n;
  cin >> p;
  while (p--) {
    cin >> k >> n;
    cout << k << ' ' << n * (n + 3) / 2 << '\n';
  }
}
