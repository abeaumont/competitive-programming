// https://open.kattis.com/problems/hangingout
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int l, x, p, current = 0, total = 0;
  cin >> l >> x;
  while (x--) {
    string s;
    cin >> s >> p;
    if (s == "enter") {
      if (current + p > l) total++;
      else
        current += p;
    } else
      current -= p;
  }
  cout << total << '\n';
}
