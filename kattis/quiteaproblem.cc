// https://open.kattis.com/problems/quiteaproblem
#include <bits/stdc++.h>

using namespace std;

bool find(string &s) {
  if (s.size() < 7) return 0;
  string upper = "PROBLEM", lower = "problem";
  for (int i = 0; i <= s.size() - 7; i++) {
    bool found = 1;
    for (int j = 0; j < 7; j++)
      if (s[i + j] != upper[j] && s[i + j] != lower[j]) {
        found = 0;
        break;
      }
    if (found) return 1;
  }
  return 0;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  while (1) {
    getline(cin, s);
    if (cin.eof()) break;
    if (find(s)) cout << "yes\n";
    else
      cout << "no\n";
  }
}
