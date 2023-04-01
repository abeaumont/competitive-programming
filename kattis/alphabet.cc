// https://open.kattis.com/problems/alphabet
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> m(1, s[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] > m.back()) {
      m.push_back(s[i]);
      continue;
    }
    auto it = lower_bound(m.begin(), m.end(), s[i]);
    *it = s[i];
  }
  cout << 26 - m.size() << '\n';
}
