// https://codeforces.com/contest/906/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<bool> x(26, 1);
  int t = 26, r = 0;
  for (int i = 0; i < n; i++) {
    string s;
    char a;
    cin >> a;
    if (a == '.') {
      cin >> s;
      for (char c : s)
        if (x[c-'a'])
          x[c-'a'] = 0, t--;
    } else if (a == '!') {
      cin >> s;
      if (t == 1) {
        r++;
        continue;
      }
      vector<bool> y(26);
      for (char c : s) y[c-'a'] = 1;
      for (int i = 0; i < 26; i++)
        if (!y[i] && x[i])
          x[i] = 0, t--;
    } else {
      cin >> a;
      if (t == 1 && !x[a-'a']) r++;
      else if (x[a-'a']) x[a-'a'] = 0, t--;
    }
  }
  cout << r << '\n';
}
