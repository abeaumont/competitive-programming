// https://cses.fi/problemset/task/2205
#include <bits/stdc++.h>

using namespace std;

void f(string &s, int n, int k) {
  if (k < 0) return;
  f(s, n, k - 1);
  s[n - k - 1] = "01"[s[n - k - 1] == '0'];
  cout << s << '\n';
  f(s, n, k - 1);
}
int main() {
  int n;
  cin >> n;
  string s(n, '0');
  cout << s << '\n';
  f(s, n, n - 1);
}
