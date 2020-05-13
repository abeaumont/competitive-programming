// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    string s;
    cin >> s;
    n = s.size();
    int d = 0;
    cout << "Case #" << T << ": ";
    for (int i=0; i<n; i++) {
      int c = s[i]-'0';
      while (d > c) d--, cout << ')';
      while (d < c) d++, cout << '(';
      cout << s[i];
    }
    for (;d;d--) cout << ')';
    cout << '\n';
  }
}
