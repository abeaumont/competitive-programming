// https://cses.fi/problemset/task/1753/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  string s, p;
  cin >> s >> p;
  int m = p.size(), n = s.size();
  string t = p + '#' + s;
  vi z(m+n+1);
  int l=0, r=0, c=0;
  for (int i=1; i<=m+n; i++) {
    z[i] = max(0, min(z[i-l], r-i));
    while (z[i]+i <= m+n && t[z[i]] == t[z[i]+i]) z[i]++;
    if (z[i]+i > r) l=i, r=z[i]+i;
    c += z[i] == m;
  }
  cout << c << '\n';
}
