// https://open.kattis.com/problems/freefood
#include <bits/stdc++.h>

using namespace std;

bool a[366];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, s, t;
  cin >> n;
  while (n--) {
    cin >> s >> t;
    for (int i = s; i <= t; i++) a[i] = 1;
  }
  int c = 0;
  for (int i = 1; i <= 365; i++) c += a[i];
  cout << c << '\n';
}
