// https://open.kattis.com/problems/dream
#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_map<string, int> m;
  vector<string> s;
  int n;
  cin >> n;
  while (n--) {
    char c;
    cin >> c;
    if (c == 'E') {
      string t;
      cin >> t;
      m[t] = s.size();
      s.push_back(t);
    } else if (c == 'D') {
      int r;
      cin >> r;
      while (r--) {
        m.erase(s.back());
        s.pop_back();
      }
    } else {
      int i = -1, j = s.size(), k;
      cin >> k;
      while (k--) {
        string t;
        cin >> t;
        if (t[0] == '!') {
          t = t.substr(1);
          if (m.count(t)) j = min(j, m[t]);
        } else {
          if (!m.count(t)) i = s.size();
          else i = max(i, m[t]);
        }
      }
      if (i < j) {
        if (j == s.size()) cout << "Yes\n";
        else cout << s.size() - j << " Just A Dream\n";
      } else cout << "Plot Error\n";
    }
  }
}
