// https://atcoder.jp/contests/abc126/tasks/abc126_a
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s[k - 1] += 32;
  cout << s << "\n";
}
