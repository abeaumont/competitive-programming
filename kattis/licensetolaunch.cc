// https://open.kattis.com/problems/licensetolaunch
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x;
  cin >> n;
  int best = 1e9 + 1;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < best) {
      best = x;
      k = i;
    }
  }
  cout << k << '\n';
}
