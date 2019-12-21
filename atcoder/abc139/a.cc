// https://atcoder.jp/contests/abc139/tasks/abc139_a
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int c = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < 3; i++) c+= s[i] == t[i];
  cout << c <<"\n";
}
