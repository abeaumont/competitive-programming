// https://www.codechef.com/DEC19A/problems/BINADD
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int l = max(s.size(), t.size());
    while (s.size() < l) s.push_back('0');
    while (t.size() < l) t.push_back('0');
    int m = 0, c = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '0' && t[i] == '0') m = max(m, c), c = 0;
      else if (s[i] == '0' && t[i] == '1') {
        if (c) c++;
        else m = max(m, max(c, 1)), c = 0;
      } else if (s[i] == '1' && t[i] == '0') {
        if (c) c++;
        else m = max(m, c), c = 0;
      } else m = max(m, c), c = 2;
    }
    m = max(m, c);
    cout << m << '\n';
  }
}
