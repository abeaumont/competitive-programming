// https://open.kattis.com/problems/heartrate
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, b;
  double p;
  cin >> n;
  while (n--) {
    cin >> b >> p;
    cout << (b - 1) * 60 / p << ' ' << b * 60 / p << ' ' << (b + 1) * 60 / p
         << '\n';
  }
}
