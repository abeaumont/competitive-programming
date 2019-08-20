// https://codeforces.com/contest/1204/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int r = s.size() / 2, c = 0;
  for (char x : s) c += x == '1';
  if (s.size() % 2 && c > 1) r++;
  cout << r << "\n";
}
