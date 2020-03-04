// https://codeforces.com/contest/1305/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  vi c(n);
  vvi r;
  while (1) {
    int i = 0, j = n-1;
    vi a;
    while (i < j) {
      if (c[i] && c[j]) i++, j--;
      else if (c[i]) i++;
      else if (c[j]) j--;
      else if (s[i] == '(' && s[j] == ')')
        c[i] = 1, c[j] = 1, a.push_back(i+1), a.push_back(j+1), i++, j--;
      else if (s[i] == '(') j--;
      else if (s[j] == ')') i++;
      else i++, j--;
    }
    if (!a.size()) break;
    sort(a.begin(), a.end());
    r.push_back(a);
  }
  cout << r.size() << '\n';
  for (int i = 0; i < r.size(); i++) {
    cout << r[i].size() << '\n';
    for (int j = 0; j < r[i].size(); j++)
      cout << r[i][j] << " \n"[j == r[i].size()-1];
  }
}
