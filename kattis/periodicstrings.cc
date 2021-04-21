// https://open.kattis.com/problems/periodicstrings
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++)
    if (s.size() % i == 0) {
      bool ok = 1;
      string t = s.substr(0, i);
      for (int j = 0; j < s.size(); j += i) {
        for (int k = 0; k < i; k++)
          if (s[j + k] != t[k]) {
            ok = 0;
            break;
          }
        if (ok) t = t.back() + t.substr(0, i - 1);
        else
          break;
      }
      if (ok) {
        cout << i << '\n';
        return 0;
      }
    }
}
