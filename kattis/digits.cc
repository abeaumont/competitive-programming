// https://open.kattis.com/problems/digits
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    string s;
    cin >> s;
    if (s == "END") break;
    if (s == "1") {
      cout << "1\n";
      continue;
    }
    int c = 2;
    int n = s.size();
    while (n > 1) {
      int len = 0;
      while (n) {
        n /= 10;
        len++;
      }
      n = len;
      c++;
    }
    cout << c << '\n';
  }
}
